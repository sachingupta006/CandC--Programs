#include<iostream>
using namespace std;
int main()
{
    cout<<"How many input alphabets are there?"<<endl;
    int in;
    cin>>in;
    cout<<"How many input states are there?"<<endl;
    int st;
    cin>>st;
    char table[st][in];
    cout<<"Enter the state table"<<endl;
    cout<<"Enter input as 0 1 ..."<<endl;
    cout<<"Enter states as A B ..."<<endl<<endl;
    char disp,start_state,end_state;
    for(int i=0;i<st;i++)
    {
        disp=(char)(i+65);
        cout<<"Enter tansition states for state "<<disp<<endl;
        for(int j=0;j<in;j++)
        {
            cout<<"Input: "<<j<<" State: ";
            cin>>table[i][j];
        }
    }
    cout<<endl<<"Enter the start state"<<endl;
    cin>>start_state;
    cout<<"Enter the accepting state"<<endl;
    cin>>end_state;
    cout<<endl<<"Table entered is"<<endl;    
    for(int i=0;i<st;i++)
    {
        for(int j=0;j<in;j++)
        {
            cout<<table[i][j]<<"\t";
        }
        cout<<endl;
    }    
    char input[20];
    cout<<endl<<"Enter input string"<<endl;
    cin>>input;
    int l=strlen(input);
    char cstate=start_state,cstate1;
    int state1;
    int state=(int)cstate - 65;
    char c;
    int inp;
    for(int i=0;i<l;i++)
    {
       c=input[i];
       inp=(int)c;
       inp-=48;
       cstate1=cstate;
       state1=(int)cstate1 - 65;
       cstate=table[state1][inp];
       cout<<"Input: "<<inp<<endl;
       cout<<"Current State: "<<cstate1<<endl;
       cout<<"Next State: "<<cstate<<endl;
       if(cstate==end_state)
              cout<<"Accepting state"<<endl;
       else
              cout<<"Non Accepting State"<<endl;

       cout<<endl;
   }     
   if(cstate==end_state)
      cout<<endl<<"The input has been accepted"<<endl;
   else
      cout<<endl<<"Inputhas not been accepted"<<endl;                     
    system("pause");
    return 0;
}    
