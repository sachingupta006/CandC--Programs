#include<iostream>
using namespace std;

class AList
{
    private:
            struct node
            {
                   int inp;
                   char state;
                   node* next;
            };
            int elements;
            node* head;
            node* current;
                                   
    public:
           AList()
           {
                  head=NULL;
                  current=NULL;
                  elements=0;
           }
           void add(int a,char b)
           {
                if(elements==0)
                {
                    node *temp=new node;      
                    temp->inp=a;
                    temp->state=b;
                    temp->next=NULL;
                    head=temp;
                    current=temp;
                }    
                else
                {
                    node *temp=new node;
                    temp->inp=a;
                    temp->state=b;
                    temp->next=NULL;
                    current->next=temp;
                    current=temp;
                }
                elements++;               
           }    
           char find(int a)
           {
                node *temp=head;
                int flag=0;
                char ret;
                while(temp!=NULL)
                {
                      if(temp->inp==a)
                      {
                         ret=temp->state;
                         flag=1;
                         break;
                      }
                      temp=temp->next;
                }
                if(flag==0)
                   ret='0';
                return ret;    
           }
           void traverse()
           {
                node* temp=head;
                while(temp!=NULL)
                {
                                       cout<<"Input: "<<temp->inp<<"\t";
                                       cout<<"State: "<<temp->state<<endl;
                                       temp=temp->next;
                }
           }   
                                                 
};
int main()
{
    cout<<"Enter the no of input alphabets"<<endl;
    int alpha;
    cin>>alpha;
    cout<<"Enter the no of states"<<endl;
    int no_states;
    cin>>no_states;
    
    AList list[no_states];
    
    char disp;
    char cstate;
    
    for(int i=0;i<no_states;i++)
    {
        disp=(char)(i+65);
        cout<<endl<<"Enter the transition states for state "<<disp<<endl;
        cout<<"If state is NULL then add 0"<<endl<<endl;
        for(int j=0;j<alpha;j++)
        {
            cout<<"Input: "<<j<<endl;
            cin>>cstate;
            if(cstate=='0')
            continue;
            else
            list[i].add(j,cstate);
        }
    }  
    char start_state,end_state;
    cout<<endl<<"Enter the start state"<<endl;
    cin>>start_state;
    cout<<"Enter the accepting state"<<endl;
    cin>>end_state;
    
    cout<<"The list transition states are"<<endl;
    for(int i=0;i<no_states;i++)
    {
            disp=(char)(i+65);
            cout<<endl<<"For State"<<disp<<endl;
            list[i].traverse();     
            cout<<endl;       
    }
    
    char input[20];
    cout<<endl<<"Enter input string"<<endl;
    cin>>input;
    int l=strlen(input);
    
    cstate=start_state;
    char cstate1;
    int state;
    
    char c;
    int inp;
    
    for(int i=0;i<l;i++)
    {
       c=input[i];
       inp=(int)c;
       inp-=48;
       cstate1=cstate;
       state=(int)cstate1 - 65;
       cstate=list[state].find(inp);
       if(cstate=='0')
       {
         cout<<"No transition"<<endl;
         system("pause");
         return 0;
       }
       else
       {
           cout<<"Input: "<<inp<<endl;
           cout<<"Current State: "<<cstate1<<endl;
           cout<<"Next State: "<<cstate<<endl;
       }
       if(cstate==end_state)
              cout<<"Accepting state"<<endl;
       else
              cout<<"Non Accepting State"<<endl;
       cout<<endl;
    }
    if(cstate==end_state)
      cout<<endl<<"The input has been accepted"<<endl;
    else
      cout<<endl<<"Input has not been accepted"<<endl;   
    system("pause");
    return 0;
}    
