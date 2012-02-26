#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
    stack<int> S1;
    stack<int> S2;
    int choice,item;
    do
    {
        cout<<"Enter your choice"<<endl;
        cout<<"1: Enqueue"<<endl;
        cout<<"2: Dequeue"<<endl;
        cout<<"3: Display"<<endl;
        cout<<"4: Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
                      case 1: cout<<"Enter the vaule to be enqueued"<<endl;
                              cin>>item;
                              S1.push(item);
                              break;
                      case 2: if (S2.isEmpty())
                              {
                                               if(S1.isEmpty())
                                               {
                                                      cout<<"Queue is empty"<<endl;
                                                      break;
                                               }
                                               else
                                               {
                                                   while(!S1.isEmpty())
                                                   {
                                                       item=S1.pop();
                                                       S2.push(item);
                                                   }
                                               }
                                               cout<<"The dequeued value is"<<S2.pop()<<endl;
                              }
                              else
                              cout<<"The dequeued value is"<<S2.pop()<<endl;
                              break;
                      case 3: cout<<"Display not available"<<endl;
                              break;
                      case 4: cout<<"You are exiting now"<<endl;
                              break;
                      default : cout<<"Invalid choice"<<endl;
                                break;
        };
    }while(choice!=4);
    system("pause");
    return 0;
}
