#include<iostream>
#include<stdio.h>
#include <string>
#include <set>

using namespace std;
set <char>::iterator si;
int done=0;
char epsilon='%';
char* null ="NULL";

int find(char *list, char val, int length)
{
    for(int i=0;i<length;i++)
    {
            if(list[i]==val)
                return i;
    }
}
    
    
class AList
{
    private:
            struct node
            {
                   char state[10];
                   node* next;
            };
            int elements;
                                   
    public:
           node* head;
           node* current;
           AList()
           {
                  head=NULL;
                  current=NULL;
                  elements=0;
           }
           void add(char* b, int length)
           {
                if(elements==0)
                {
                    node *temp=new node;      
                    int i;
                    for(i=0;i<length;i++)
                    {
                            temp->state[i]=b[i];
                    }
                    temp->state[i]='\0';
                    temp->next=NULL;
                    head=temp;
                    current=head;


                }    
                else
                {
                    node *temp=new node;
                    int i;
                    for(i=0;i<length;i++)
                    {
                            temp->state[i]=b[i];
                    }
                    temp->state[i]='\0';
                    temp->next=NULL;
 
                    current->next=temp;
                    current=temp;
                }
                elements++;               
           }    
               
};
void calculateFIRST(int i,int index, AList* list,int no_nonTerminals,int no_terminals, char* nonTerminals,char *terminals,set <char> *FIRST )
{
       list[i].current=list[i].head; 
       int flag=1;
       int start=0;
       while(list[i].current!=NULL)
           {
                               char temp=list[i].current->state[start];
                               if(temp >64 && temp < 92)
                               {
                                       while( flag==1)
                                       {
                                                    int ntIndex=find(nonTerminals,temp,no_nonTerminals);
                                                    si=FIRST[ntIndex+index].begin();
                                                    if(si==FIRST[ntIndex+index].end())
                                                    {
                                                        cout<<endl;
                                                        calculateFIRST( ntIndex,index,list,no_nonTerminals,no_terminals,nonTerminals,terminals,FIRST);
                                                    }
                                                    else
                                                    {
                                                        for (si=FIRST[ntIndex+index].begin(); si!=FIRST[ntIndex+index].end(); si++) 
                                                        {
                                                            FIRST[i+index].insert(*si);
                                                            if(*si=='%')
                                                            {
                                                                        flag=1;
                                                                        start++;
                                                                        temp=list[i].current->state[start];
                                                            }
                                                            else
                                                            {
                                                              flag=0;
                                                            }
                                                        }
                                                    }
                                       }
                               }
                               else
                               {
                                   char temp=list[i].current->state[0];
                                   if(temp=='%')
                                   {
                                       FIRST[i+index].insert('%');

                                   }
                                   else
                                   {
                                       int tIndex=find(terminals,temp,no_terminals);
                                       si=FIRST[tIndex].begin();
                                       FIRST[i+index].insert(*si);

                                   }
                               }
                           list[i].current=list[i].current->next;    

                               
           } 
           done++;
}          
                   
int main()
{

    cout<<"Enter the no of non-terminals"<<endl;
    int no_nonTerminals;
    cin>>no_nonTerminals;
    
    cout<<"Enter the no of terminals"<<endl;
    int no_terminals;
    cin>>no_terminals;
    no_terminals++;
    
    AList list[no_nonTerminals];                //set of productions for each non terminal
    char nonTerminals[no_nonTerminals];
    char terminals[no_terminals];
    
    set <char> FIRST[no_nonTerminals+no_terminals+1];   // FIRST set for all terminals and non terminals     
    set <char> FOLLOW[no_nonTerminals];               // fOLLOW set only for non terminals
    set <char> FIRSTSET;
    
    char* parsingTable[no_nonTerminals][no_terminals+1];       // parsing table initiated with string NULL as initial value
    for (int i=0;i< no_nonTerminals;i++)
    {
        for(int j=0;j<no_terminals;j++)
        {
                parsingTable[i][j]=null;
        }
    }
    
    cout<<"Enter the terminals"<<endl;
    char term;
    int index;
    for( index = 0;index < no_terminals-1;index++)
    {
            cin>>term;
            terminals[index]=term;
            FIRST[index].insert(term);
    }
    term='$';
    terminals[index]=term;
    FIRST[index].insert(term);
    index++;
    
    cout<<"The FIRST set for the terminals is"<<endl;
    for(int l=0;l<no_terminals;l++)
    {
            si=FIRST[l].begin();
            cout<<*si<<"    ";
    }   
    
    cout<<endl<<"Enter the productions for the non-terminals"<<endl<<endl;
    cout<<"For epsilon production enter % "<<endl;
    char state;
    char inp[10];
    for(int i=0;i<no_nonTerminals;i++)
    {
            cout<<"Enter the Non-terminal"<<endl;
            cin>>state;
            nonTerminals[i]=state;
            cout<<"Enter the productions. Enter 0 when done"<<endl;
            cin>>inp;
            while(inp[0]!='0')
            {
                              int len=strlen(inp);
                              list[i].add(inp,len);
                              cin>>inp;
            }                        
    }
    cout<<"Productions added are"<<endl<<endl;
    for(int count=0;count<no_nonTerminals;count++)
    {
        list[count].current=list[count].head;
        while(list[count].current!=NULL)
        {
            cout<<nonTerminals[count]<<" -> "<<list[count].current->state<<"   ";
            list[count].current=list[count].current->next;
        }
        cout<<endl;
        
    }        
    cout<<"Enter the start symbol"<<endl;
    char start;
    cin>>start;

    int ntIndex=find(nonTerminals,start,no_nonTerminals);
    FOLLOW[ntIndex].insert('$');
    calculateFIRST( ntIndex,index,list,no_nonTerminals,no_terminals,nonTerminals,terminals,FIRST);         //calculate the FIRST set
    
    int check=0;
    while(done!=no_nonTerminals)
    {
        if(FIRST[check+index].begin()==FIRST[check+index].end())
            calculateFIRST( check,index,list,no_nonTerminals,no_terminals,nonTerminals,terminals,FIRST);
        else
        {

            check++;
            continue;
        }    
    }
    cout<<endl<<"------- FIRST set---------"<<endl;    
    for(int l=index;l<no_nonTerminals+index;l++)
    {
        cout<<"For "<<nonTerminals[l-index]<<":    ";
        for (si=FIRST[l].begin(); si!=FIRST[l].end(); si++)  
        {  
           cout << *si << " ";  
        }
        cout<<endl;
    }
    cout<<endl<<"------- FOLLOW set---------"<<endl;
    //cout<<"First pass"<<endl;
    for(int count=0;count<no_nonTerminals;count++)
    {
        list[count].current=list[count].head;
        while(list[count].current!=NULL)
        {
            //cout<<endl;
            //cout<<"For "<<nonTerminals[count]<<" -> "<<list[count].current->state<<endl;
            int index1=0;
            int flag=0;
            char c1,c2;
            int i1,i2;
            while(list[count].current->state[index1]!='\0')
            {
                c1=list[count].current->state[index1];
                if(c1>=65 && c1<=90)
                {
                     c2=list[count].current->state[index1+1];
                     i1=find(nonTerminals,c1,no_nonTerminals);
                     if(c2!='\0')
                     {            
                           if(c2>=65 && c2<=90)
                           {
                                i2=find(nonTerminals,c2,no_nonTerminals);
                                for (si=FIRST[i2+index].begin(); si!=FIRST[i2+index].end(); si++)
                                {
                                    if(*si!='%')
                                    {
                                        FOLLOW[i1].insert(*si);
                                        //cout<<"Added: "<<*si<<"to FOLLOW set of "<<nonTerminals[i1]<<endl;
                                    }                                       
                                }     
                           }
                           else
                           {
                                i2=find(terminals,c2,no_terminals);
                                si=FIRST[i2].begin();
                                FOLLOW[i1].insert(*si);
                                //cout<<"Added: "<<*si<<"to FOLLOW set of "<<nonTerminals[i1]<<endl;
                           }                         
                     }
                     /*
                     else
                     {
                         cout<<"next symbol Null so jumped"<<endl;
                     }*/
                }
                
                /*
                else
                {
                    cout<<"Not a Non-terminal"<<endl;
                }
                */
                index1++;
            }            
            list[count].current=list[count].current->next;
        }
    }  
    //cout<<endl<<"Second Pass"<<endl;    
    for(int count=0;count<no_nonTerminals;count++)
    {
        list[count].current=list[count].head;
        while(list[count].current!=NULL)
        {
            //cout<<endl;
            //cout<<"For "<<nonTerminals[count]<<" -> "<<list[count].current->state<<endl;
            int index1=0;
            int flag=0;
            char c1,c2;
            int i1,i2;
            while(list[count].current->state[index1]!='\0')
            {
                c1=list[count].current->state[index1];
                if(c1>=65 && c1<=90)
                {
                     c2=list[count].current->state[index1+1];
                     //cout<<c2;
                     i1=find(nonTerminals,c1,no_nonTerminals);
                     if(c2!='\0')
                     {            
                           if(c2>=65 && c2<=90)
                           {
                                i2=find(nonTerminals,c2,no_nonTerminals);
                                si=FIRST[i2+index].find(epsilon);
                                if(si!=FIRST[i2+index].end())
                                {
                                     //cout<<"Found epislon in FIRST of "<<nonTerminals[i2]<<endl;
                                     for(si=FOLLOW[count].begin();si!=FOLLOW[count].end(); si++)
                                     {
                                        FOLLOW[i1].insert(*si);
                                        //cout<<"Ädded: "<<*si<<"to FOLLOW set of "<<nonTerminals[i1]<<endl;
                                     }
                                }
                           }
                     }
                     else
                     {
                                //cout<<"next symbol is NULL"<<endl;
                                //i2=find(nonTerminals,c2,no_nonTerminals);
                                for(si=FOLLOW[count].begin();si!=FOLLOW[count].end(); si++)
                                {
                                        FOLLOW[i1].insert(*si);
                                        //cout<<"Ädded: "<<*si<<"to FOLLOW set of "<<nonTerminals[i1]<<endl;
                                }
                     }                         
                }
                /*
                else
                {
                    cout<<"Not a Non terminal"<<endl;
                }
                */
                index1++;
            }            
            list[count].current=list[count].current->next;
        }
    } 
    for(int l=0;l<no_nonTerminals;l++)
    {
        cout<<"For "<<nonTerminals[l]<<":    ";
        for (si=FOLLOW[l].begin(); si!=FOLLOW[l].end(); si++)  
        {  
           cout << *si <<" ";  
        }
        cout<<endl;
    }   
    cout<<"Making the Parsing Table."<<endl;
    //char* end;
    //cin>>end;
    for(int count=0;count<no_nonTerminals;count++)
    {
        list[count].current=list[count].head;
        while(list[count].current!=NULL)
        {
            cout<<endl<<"For "<<nonTerminals[count]<<" -> "<<list[count].current->state<<endl;
            int index1=0;
            char c1,c2;
            int i1,i2;
            while(list[count].current->state[index1]!='\0')
            {
                c1=list[count].current->state[index1];
                if(c1>=65 && c1<=90)
                {
                     i1=find(nonTerminals,c1,no_nonTerminals);
                      cout<<"Adding: ";
                     for (si=FIRST[i1+index].begin(); si!=FIRST[i1+index].end(); si++)
                     {
                         if(*si != epsilon)
                         {
                             FIRSTSET.insert(*si);
                             cout<<*si<<"   ";
                         }
                     }
                     si=FIRST[i1+index].find(epsilon);
                     if(si==FIRST[i1+index].end())
                        break;
                }
                else
                {
                   if(c1=='%')
                   {
                         cout<<"Epsilon production"<<endl;
                         cout<<"Adding: ";
                         for(si=FOLLOW[count].begin();si!=FOLLOW[count].end();si++)
                         {
                             cout<<*si<<"   ";
                             FIRSTSET.insert(*si);
                         }
                         break;
                             
                   }
                   else
                   {
                        i1=find(terminals,c1,no_terminals); 
                        //cout<<"Adding: ";
                        si=FIRST[i1].begin();
                        FIRSTSET.insert(*si);
                        //cout<<*si<<"  ";
                        break;
                   }
                }
                index1++;
            }
            if(list[count].current->state[index1]=='\0')
            {
                 for(si=FOLLOW[count].begin();si!=FOLLOW[count].end();si++)
                     FIRSTSET.insert(*si);
            }
            cout<<endl<<"First Set:  ";
            for (si=FIRSTSET.begin(); si!=FIRSTSET.end(); si++)
            {
                cout<<*si<<" ";
                c2=*si;
                i2=find(terminals,c2,no_terminals);
                parsingTable[count][i2]=list[count].current->state;
            }   
            list[count].current=list[count].current->next;
            FIRSTSET.clear();
            cout<<endl;
        }
    }
    cout<<endl;
    cout<<endl<<"------------------ Parsing Table --------------------"<<endl;
    cout<<"         ";
    for(int i=0;i<no_terminals;i++)
            cout<<"   "<<terminals[i]<<"    "; 
    cout<<endl<<endl;;    
    for(int i=0;i<no_nonTerminals;i++)
    {
            cout<<"    "<<nonTerminals[i]<<"    ";
            for(int j=0;j<no_terminals;j++)
            {
                    if(parsingTable[i][j]!=null)
                         cout<<"   "<<parsingTable[i][j]<<"    ";
                    else
                    {
                        cout<<"        ";
                    }
            }
            cout<<endl;
    }                  
    cout<<endl<<"------------------------------------------------------"<<endl;
    system("pause");
    return 0;
}
