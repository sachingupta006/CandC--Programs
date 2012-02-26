#include<iostream>
#include<stdio.h>
#include"Stack1.h"
using namespace std;

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
int find_prod( AList* list, int no_nonTerminals, char term, char* nonTerminals)
{
    for(int count=0;count<no_nonTerminals;count++)
    {
        list[count].current=list[count].head;
        while(list[count].current!=NULL)
        {
            char* c=list[count].current->state;
            while(*c)
            {
               if(*c==term)
               {
                   cout<<nonTerminals[count]<<" -> "<<list[count].current->state;
                   return count;
               }    
               else
                 c++;
            }
            list[count].current=list[count].current->next;
        }
    } 
    return -1;
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
    
    cout<<"Enter the terminals"<<endl;
    char term;
    int index;
    for( index = 0;index < no_terminals-1;index++)
    {
            cin>>term;
            terminals[index]=term;
    }
    term='$';
    terminals[index]=term;
    index++;
    
    
    cout<<endl<<"Enter the productions for the non-terminals"<<endl<<endl;
    cout<<"For epsilon production enter % "<<endl;
    char state;
    char production[10];
    for(int i=0;i<no_nonTerminals;i++)
    {
            cout<<"Enter the Non-terminal"<<endl;
            cin>>state;
            nonTerminals[i]=state;
            cout<<"Enter the productions. Enter 0 when done"<<endl;
            cin>>production;
            while(production[0]!='0')
            {
                              int len=strlen(production);
                              list[i].add(production,len);
                              cin>>production;
            }                        
    }
    cout<<"Productions added are"<<endl<<endl;
    for(int count=0;count<no_nonTerminals;count++)
    {
        list[count].current=list[count].head;
        while(list[count].current!=NULL)
        {
            cout<<list[count].current->state<<" ";
            list[count].current=list[count].current->next;
        }
        cout<<endl;
        
    }  
    char table[no_terminals][no_terminals];
    cout<<"Enter the operator precedence table"<<endl;
    
    cout<<"\t";
    for(int i=0;i<no_terminals;i++)
    cout<<terminals[i]<<"\t";
    
    for(int i=0;i<no_terminals;i++)
    {
            cout<<endl<<terminals[i]<<"\t";
            for(int j=0;j<no_terminals;j++)
                    cin>>table[i][j];
    }          
                    
    stack<char> S;
    S.push('$');
    char inp[10];
    cout<<"Enter the input"<<endl;
    cin>>inp;
    cout<<endl;
    int length=strlen(inp);
    inp[length]='$';
    length++;
    inp[length]='\0';
    cout<<"Parsing the input"<<endl;
    char* ptr=inp;
    cout<<endl;
    cout<<"Stack\tRelation Input\tProduction"<<endl;
    while(true)
    {
               if(S.peep()=='$' && (*ptr) == '$')
                  break;
               else
               {
                   char a=S.peep();
                   char b=*ptr;
                   int i=find(terminals,a,no_terminals);
                   int j=find(terminals,b,no_terminals);
                   S.display();
                   cout<<"\t"<<table[i][j]<<"\t "<<ptr<<"\t";
                   if(table[i][j] == '<' || table[i][j] == '=' )
                   {
                      S.push(b);
                      ptr++;
                   }
                   else if(table[i][j] == '>')
                   {
                        char c=S.peep();
                        int k=find_prod(list, no_terminals,c,nonTerminals);
                        do
                        {
                           char c=S.pop();
                           b=S.peep();
                           i=find(terminals,b,no_terminals);
                           j=find(terminals,c,no_terminals);
                        }while(table[i][j]!='<');
                   } 
                   else
                   {
                       cout<<"Error"<<endl;
                       break;
                   }
                   cout<<endl;
               }
    } 
    S.display();
    cout<<"\t\t "<<ptr<<endl; 
    if(S.peep()=='$' && (*ptr) == '$')
      cout<<endl<<"Input accepted"<<endl;    
    system("pause");
    return 0;
}
