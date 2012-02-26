#include<iostream>
using namespace std;

class node{
    public:
        int info;
        node *next;
};
class stack{
    protected:
        node *top;
    public:
        int count;
        stack(){
            top=NULL;
            count=0;
        }
        void push(int value){
            count++;
            node *temp=new node;
            temp->info=value;
            temp->next=top;
            top=temp;
        }
        
        int pop()
        {
            count--;
            int val;
            node *temp;
            val=top->info;
            temp=top;
            top=top->next;
            delete temp;
            return val;
        }
            
}s_h,s_o;

void hReady(void);
void oReady(void);
void makewater(void);
int h=0;
int o=0;
int h1=0;
int o1=0;
int index=0;
int atom[10];

int main()
{
    
    cout<<"Enter 10 atom: 1-Hydrogen 0-Oxygen"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>atom[i];
    }    
    if(atom[index]==1)
    hReady();
    else
    oReady();                    
    system("pause");
    return 0;
}   


void hReady()
{
     if(index>10)
    return;
    if(s_h.count>=2&&s_o.count>=1)
    {   
        index--;
        makewater();
    }
    else
    {
        
           s_h.push(atom[index]);
               index++;
               
                 if(atom[index]==1)
                     hReady();
                 else
                     oReady();
           } 
    /*else if(s_h.count>=2&&s_o.count<1)
    {
        index++;
         if(atom[index]==1)
             hReady();
         else
             oReady();
    }
     
     else if(s_h.count<2)
           {
               s_h.push(atom[index]);
               index++;
               
                 if(atom[index]==1)
                     hReady();
                 else
                     oReady();
           } 
}     */           
 
     }        
  
void oReady()
{
     if(index>10)
    return;
    if(s_h.count>=2&&s_o.count>=1)
    {   
        index--;
        makewater();
    }
    else
    {
        s_o.push(atom[index]);
               index++;
               
                 if(atom[index]==1)
                     hReady();
                 else
                     oReady();
    } 
        
   /* else if(s_o.count>=1&&s_h.count<2)
    {
        index++;
         if(atom[index]==1)
             hReady();
         else
             oReady();
    }
     
     else if(s_o.count<1)
           {
               s_o.push(atom[index]);
               index++;
               
                 if(atom[index]==1)
                     hReady();
                 else
                     oReady();
           } 
}    */            
  }           
  void makewater()
  {
      
      cout<<s_h.pop();
      cout<<s_h.pop();
      cout<<s_o.pop();
      cout<<"water made"<<endl;
     // int j=s_h.count;
      
     /* for(int i=0;i<j;i++)
      { 
          // int k=s_h.pop();
          cout<<s_h.pop()<<endl;
          //s_h.push(k);
      }*/    
          
            
            
            index++;
         if(atom[index]==1)
             hReady();
         else
             oReady();
  }    
                                                     
             
                                      
                                
        
