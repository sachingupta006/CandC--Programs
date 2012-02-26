#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
    stack<int> S1;
    stack<int> S2;
    int choice,item,item1;
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
                              if(S2.isEmpty())
                              S2.push(item);
                              else
                              {
                                  while(!S2.isEmpty())
                                  {
                                     item1=S2.pop();
                                     S1.push(item1);
                                  }
                                  S1.push(item);
                                  while(!S1.isEmpty())
                                  {
                                     item1=S1.pop();
                                     S2.push(item1);
                                  }
                              }
                              break;
                      case 2: if (S2.isEmpty())
                              cout<<"The Queue is empty"<<endl;
                              else
                              cout<<"The dequeued value is"<<S2.pop()<<endl;
                              break;
                      case 3: cout<<"The Queue is"<<endl;
                              S2.display();
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
