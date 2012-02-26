#include<iostream>
#include"stack.h"
using namespace std;
bool isDigit(char a)
{
    if(a>='0'&&a<='9')
    return true;
    else
    return false;
}
int convert(char b)
{
    return ((int)b-48);
} 
int precedence(char c)
{
    if(c=='*'||c=='/')
    return 2;
    else
    return 1;
}           
int main()
{
    int num1,num2,num;
    char sym,temp;
    char in[20];
    stack<char>S1;
    stack<char>S2;
    cout<<"Enter the infix string"<<endl;
    cin>>in;
    int j=0;
    do
    {
        if(isDigit(in[j]))
        {
            S1.push(in[j]);
            j++;
        }    
        else
        {
            if(S2.isEmpty())
            {
                S2.push(in[j]);
                j++;
            }
            else if(precedence(in[j])==2)
            {
                S2.push(in[j]);
                j++;
            }
            else
            {
                num1=convert(S1.pop());
                num2=convert(S1.pop());
                sym=S2.pop();
                switch(sym)
                {
                    case '+': 
                        num=num2+num1;
                        temp=((char)num + 48);
                        S1.push(temp);
                        break;
                    case '-':
                        num=num2-num1;
                        temp=((char)num + 48);
                        S1.push(temp);
                        break;
                    case '*': 
                        num=num2*num1;
                        temp=((char)num + 48);
                        S1.push(temp);
                        break;
                    case '/':
                        num=num2/num1;
                        temp=((char)num + 48);
                        S1.push(temp);
                        break;
                    default: cout<<"Invalid Operator"<<endl;
                }
            }
        }
    }while(in[j]!='\0');
    if(S2.isEmpty())
    {
        cout<<"The value of the infix string is"<<endl;
        temp=S1.pop();
        num=convert(temp);
        cout<<num;
    }    
    else
    {
        while(!S2.isEmpty())
        {
                num1=convert(S1.pop());
                num2=convert(S1.pop());
                sym=S2.pop();
                switch(sym)
                {
                    case '+': 
                        num=num2+num1;
                        temp=((char)num + 48);
                        S1.push(temp);
                        break;
                    case '-':
                        num=num2-num1;
                        temp=((char)num + 48);
                        S1.push(temp);
                        break;
                    case '*': 
                        num=num2*num1;
                        temp=((char)num + 48);
                        S1.push(temp);
                        break;
                    case '/':
                        num=num2/num1;
                        temp=((char)num + 48);
                        S1.push(temp);
                        break;
                    default: cout<<"Invalid Operator"<<endl;
                }
        }
        cout<<"The value of the infix string is"<<endl;
        temp=S1.pop();
        num=convert(temp);
        cout<<num;
    }
    cout<<endl;
    system("pause");
    return 0;
}
    
    
            
                 
                 
                    
                        
                                              
                
            
        
        
        

        
