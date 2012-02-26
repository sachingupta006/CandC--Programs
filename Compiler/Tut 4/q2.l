%{
	#include <stdlib.h>
	void yyerror(char *);
	#include "y.tab.h"
%}
%%
"true"		{ yylval=1;
		  return bool;
		}
"false"		{
		  yylval=0;
		  return bool;
		}
"or"		{ return or; }
"and" 		{ return and; }
"not"		{ return not; }
[()\n]      	return *yytext;
[ \t]       	; /* skip whitespace */
.           	yyerror("invalid character");
%%
int yywrap(void) {
    return 1;
}

