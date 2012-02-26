#include<iostream>
using namespace std;
int main()
{
    char inp[20];
    cout<<"Enter the input string"<<endl;
    cin>>inp;
    int l= strlen(inp);
    int state=1;
    int state1;
    char cstate,cstate1,c;
    for(int i=0;i<l;i++)
    {
        switch(state)
        {
            case 1: 
            state1=1;
            cstate1='A';
            c=inp[i];
            if(c=='0')
            {
                state=2;
                cstate='B';
            }
            else if(c=='1')
            {
                state=1;
                cstate='A';
            }
            else if (c=='2')
            {
                state=2;
                cstate='B';
            }
            else state=0;            
            break;
        case 2: 
            state1=2;
            cstate1='B';
            c=inp[i];
            if(c=='0')
            {
                state=5;
                cstate='E';
            }
            else if(c=='1')
            {
                state=1;
                cstate='A';
            }
            else if (c=='2')
            {
                state=3;
                cstate='C';
            }
            else state=0;            
            break;
        case 3: 
            state1=3;
            cstate1='C';
            c=inp[i];
            if(c=='0')
            {
                state=1;
                cstate='A';
            }
            else if(c=='1')
            {
                state=5;
                cstate='E';
            }
            else if (c=='2')
            {
                state=4;
                cstate='D';
            }
            else state=0;            
            break;
        case 4: 
            state1=4;
            cstate1='D';
            c=inp[i];
            if(c=='0')
            {
                state=3;
                cstate='C';
            }
            else if(c=='1')
            {
                state=4;
                cstate='D';
            }
            else if (c=='2')
            {
                state=5;
                cstate='E';
            }
            else state=0;            
            break;
        case 5: 
            state1=5;
            cstate1='E';
            c=inp[i];
            if(c=='0')
            {
                state=5;
                cstate='E';
            }
            else if(c=='1')
            {
                state=4;
                cstate='D';
            }
            else if (c=='2')
            {
                state=1;
                cstate='A';
            }
            else state=0;            
            break;    
          case 0:
              cout<<"Invalid input"<<endl;
              system("pause");
              return 0;
          default:
              cout<<"Invalid state or input"<<endl;
              system("pause");
              return 0;
       }
       cout<<"Input: "<<c<<endl;
       cout<<"Current state: "<<cstate1<<endl;
       cout<<"Next state: "<<cstate<<endl;
       if(cstate=='E')
              cout<<"Accepting State"<<endl;
       else
              cout<<"Non Accepting state"<<endl;
       cout<<endl;       
    }    
    system("pause");
    return 0;
}    
                          
            
            
