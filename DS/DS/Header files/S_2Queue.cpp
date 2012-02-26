#include<iostream>
#include"Queue.h"
using namespace std;
int main()
{
    Queue<int> Q1;
    Queue<int> Q2;
    int choice,item,counter=0;
    do
    {
        cout<<"Enter your choice"<<endl;
        cout<<"1: PUSH the data"<<endl;
        cout<<"2: POP the data"<<endl;
        cout<<"3: Display"<<endl;
        cout<<"4: Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
                      case 1: Q1.Enqueue();
                              counter++;
                              break;
                      case 2: if(Q1.isEmpty())
                              cout<<"The Stack is empty"<<endl;
                              while(counter!=1)
                              {
                                 item=Q1.Dequeue();
                                 Q2.Enqueue(item);
                                 counter--;
                              }
                              cout<<"The item dequeued is"<<endl;
                              Q1.Dequeue();
                              
                              break;
                      case 3: S.display();
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
