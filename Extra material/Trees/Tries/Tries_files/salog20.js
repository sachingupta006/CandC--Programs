
HubspotLog = function()
{
	this.referer = null;
	this.title = null;
	this.url = null;
	this.base_dir = null;
	this.error=0;
	this.guid=null;
	this.isNewDailyVisitor = false;	
	this.isNewWeeklyVisitor = false;
	this.isNewMonthlyVisitor = false;
	this.NewVisit =0;
	this.PrevOnload=null;
	this.PortalID=window.hs_portalid;
	this.PrimaryPortalAlias=window.hs_ppa;
	this.lastVisitTimeStamp = "";
	this.FirstVisitValue = window["hsFirstVisitValue"];

	if (typeof(this.PrimaryPortalAlias)=='string')
		this.PrimaryPortalAlias=this.PrimaryPortalAlias.replace(/\s+/g, '');
	if (typeof(this.PrimaryPortalAlias)!='string' || 
	(typeof(this.PrimaryPortalAlias)=='string' && this.PrimaryPortalAlias.length <= 0))
		this.PrimaryPortalAlias = "pg2.hubspot.com";
}

HubspotLog.prototype = {
	Init : function() {

		this.PrevOnload = null;
		if (typeof(window.onload) == 'function')
			this.PrevOnload = window.onload;
		window.onload = function() { hslog.Log.call(hslog); };
		if (!this.FirstVisitValue) {
		    this.FirstVisitValue = this.ReadCookie("hsfirstvisit");
		}
		document.writeln('<span id="hsjssp"></span>');
	},
	
	CreateGuid : function() {
		var g = "";
		for(var i = 0; i < 32; i++)
		g += Math.floor(Math.random() * 0xF).toString(0xF)
		return g;
	},
	CreateCookie : function(c_name,value,expiredays, dontEscape){
		var exdate=new Date()
		exdate.setDate(exdate.getDate()+expiredays)
		if (!(dontEscape)) {
		   value = escape(value);
		} 
		document.cookie=c_name+ "=" + value + ((expiredays==null) ? "" : ";path=/;expires="+exdate.toGMTString())
	},
	ReadCookie : function(c_name){
		if (document.cookie.length>0)
		  {
		  c_start=document.cookie.indexOf(c_name + "=")
		  if (c_start!=-1)
			{ 
			c_start=c_start + c_name.length+1 
			c_end=document.cookie.indexOf(";",c_start)
			if (c_end==-1) c_end=document.cookie.length
			return unescape(document.cookie.substring(c_start,c_end))
			} 
		  }
		return null
	},
	ManageCookie : function(){
	    var dtCookie = this.ReadCookie("hubspotdt");
	    if (dtCookie) {
	        this.lastVisitTimeStamp = dtCookie;
	    }
	    this.CreateCookie("hubspotdt", hsTimeStamp, 3650, false);	            	
	
		var tguid = tguid = this.ReadCookie("hubspotutk");
	
		if (tguid){
		
			this.NewVisit=0; 
			this.guid=tguid; 
			return;
		}
		
		if (tguid == null && typeof(window['hsut']) == 'string') {
			tguid = window['hsut'];
		}		
		if (!tguid) {
		   tguid = this.CreateGuid();
		}
		if (tguid.indexOf('-') != -1) {
				tguid = tguid.replace(/\-/g, '');
		}		
		this.guid = tguid;
		this.CreateCookie("hubspotutk", this.guid, 3650, false);
		this.guid = this.ReadCookie("hubspotutk"); // to make sure we are able to set the cookie
		if (hsIsNewVisitor) {
		    this.NewVisit=1;
		}
		return;
	},
	CreateCookiePrecise : function(c_name, value, expireSeconds) {
		var exdate=new Date()
		exdate.setSeconds(exdate.getSeconds()+expireSeconds)
		document.cookie=c_name+ "=" +escape(value)+ ((expireSeconds==null) ? "" : ";path=/;expires="+exdate.toGMTString())	
	},
	/*  We don't want to exceed the size reserved by browser for cookie data per domain */
	TruncateString : function(s, maxlength) {
	    if (!s) {
	       return "";
	    }
	    if (s.length > maxlength) {
	       return s.substr(0, maxlength);
	    }
	    return s;
	},
	/* Set a cookie to hold the first url and referrer, we can use this to
	   generate the source as soon as lead converts */	
	ManageFirstVisitCookie : function() {
	    if (this.NewVisit) {
	        // Both url and referrer are already url encoded, so we can safely use
	        // the pipe as a delimeter.
	        var val = this.TruncateString(this.url, 750) + "|" + this.TruncateString(this.referer, 750) + "|" + encodeURIComponent(hsTimeStamp);
	        this.CreateCookie("hsfirstvisit", val, 3650, true);
	        this.FirstVisitValue = val;
	    }	
	},
	ManagePeriodicCookies : function(){ 	
	    var daily = this.ReadCookie("hubspotvd");
	    if (!daily) {
	       this.CreateCookiePrecise("hubspotvd", this.guid, hsDayEndsIn);
	       this.isNewDailyVisitor = true;
	    }
	    var weekly = this.ReadCookie("hubspotvw");
	    if (!weekly) {
	       this.CreateCookiePrecise("hubspotvw", this.guid, hsWeekEndsIn);
	       this.isNewWeeklyVisitor = true;
	    }	  	    
	    var monthly = this.ReadCookie("hubspotvm");
	    if (!monthly) {
	       this.CreateCookiePrecise("hubspotvm", this.guid, hsMonthEndsIn);
	       this.isNewMonthlyVisitor = true;
	    }	    
	    
	},
	// Insert the first visit information into a hidden field
	// so that the info will be passed to the CMS when the form
	// is submitted.  Ideally, this would be in the form code itself,
	// but it's too difficult to go back and re-export every exported
	// form for every customer
	InsertFirstVisitDataIntoForm : function() {
	    var idField = document.getElementById("ContactFormId");
	    var firstVisitVal = this.FirstVisitValue;
	    for (var i = 0; i < document.forms.length; i++) {
	        var form = document.forms[i];
	        if (form["ContactFormId"] && firstVisitVal) {
	            var newInput = document.createElement("input");
	            newInput.setAttribute("type", "hidden");
	            newInput.setAttribute("value", firstVisitVal);
	            newInput.setAttribute("name", "hsFirstVisitHidden");
	            form.appendChild(newInput);
	        }
	    }
	},
	// If this is the first visit for the user, we have set
	// the hsfirstvisit cookie.  But this cookie is not
	// associated with the sitename.hubspot.com domain.
	// As a result if the user crosses domain (ie, crosses over
	/// to a HubSpot landing page), that FirstVisit information
	// will be lost.  Thus we make a call back to sitename.hubspot.com
	// and give it the information it needs to be able to set 
	// the server side cookie.
	LogFirstVisit : function() {

	    if (!this.NewVisit) {
	        return;
	    }
	    
	    if (!this.FirstVisitValue) {
	        return;
	    }
	    
	    var url = document.location.protocol + "//" + this.PrimaryPortalAlias + "/SAFirstVisitHandler.aspx?" +
	              "hsFirstVisitCookieVal=" + encodeURIComponent(this.FirstVisitValue);
	    var html = "<img src='"+ url + "' border='0' width='0' height='0'/>";
        var span = document.getElementById("hsjssp");
		if (span != null) span.innerHTML += html;

	},
	Log : function(){
		if (this.PrevOnload != null) {
			try {
				this.PrevOnload();
			} catch(e){}
		}
	
		var El = "";
		try
		{
			if (document.location.protocol.toLowerCase().indexOf("http") != 0) return null;
			this.base_dir = document.location.protocol + "//" + this.PrimaryPortalAlias + "/salog.aspx?";

			if(typeof(this.PortalID) != 'undefined') this.base_dir += "p="+this.PortalID; else this.error = 1;

			this.referer = ""+document.referrer;
			this.title = typeof(window.hs_title) != "string"? ""+document.title : window.hs_title;
			this.url = ""+document.location;		
			this.referer = encodeURIComponent(this.referer.replace(/\.{2}/g, ''));
			this.title = encodeURIComponent(this.title.replace(/\.{2}/g, ''));
			this.url = encodeURIComponent(this.url.replace(/\.{2}/g, ''));
			
			this.ManageCookie();
			this.ManagePeriodicCookies();
			this.ManageFirstVisitCookie();
			this.InsertFirstVisitDataIntoForm();
			if (!this.guid)
				this.guid = this.CreateGuid();
			else
				this.guid = encodeURIComponent(this.guid);

			if(this.error==1) 
				El = "<small>Hubspot Site Analysis code corrupted. Insert fresh copy.</small>";
			else 
			{
				var query = this.GenerateQueryString20(); 
				var tracking_url = document.location.protocol + "//"+hsAnalyticsServer+"/track?" + query;
				tracking_url = tracking_url.replace(/'/g, '%27');
				El += "\n<img src='"+ tracking_url + "' border='0' width='0' height='0'/>";				    
								
			}
			this.LogFirstVisit();
		}
		catch(e)
		{
			El = "<small>Hubspot Site Analysis Error - "+e.number+" : "+e.message+"</small>";
		}
		
		if (El != null && El) {
			var span = document.getElementById("hsjssp");
			if (span != null) span.innerHTML += El;
		}
		
		return null;
	},
	GetExperimentsCookie : function() {
	    if (window["hsExperimentsCookieVal"]) {
	        return window["hsExperimentsCookieVal"];
	    } else {
	       return "";
	    }
	},
	GenerateQueryString20 : function() {
	    var query = "&g="+this.guid+"&n="+this.NewVisit+"&u="+this.url+"&r="+this.referer+"&t="+this.title;
        if (this.isNewDailyVisitor) {
	        query += "&nD=1";
	    }	    
	    if (this.isNewWeeklyVisitor) {
	        query += "&nW=1";
	    }
        if (this.isNewMonthlyVisitor) {
	        query += "&nM=1";
	    }

        query += "&p="+this.PortalID;	
        query += "&lvt="+this.lastVisitTimeStamp;
        query += "&cvt="+hsTimeStamp;   
        
	    var expCookieVal = this.GetExperimentsCookie();
	    if (expCookieVal) {
	        query += "&ev=" + expCookieVal;
	    }
	            
	    return query; 
	}
}

if (typeof(window['hslog']) == 'undefined') {
	var hslog = new HubspotLog();
	hslog.Init();
}