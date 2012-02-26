#include<iostream>
#include"Deque.h"
using namespace std;
int main()
{
    Dque<int> D1;
    int choice,item;
    cout<<endl;
    cout<<"What do you want to use"<<endl;
    cout<<"1: Queue"<<endl;
    cout<<"2: Stack"<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1: 
        do
        {
        cout<<"Enter your choice"<<endl;
        cout<<"1: Enqueue data"<<endl;
        cout<<"2: Dequeue data"<<endl;
        cout<<"3: Display"<<endl;
        cout<<"4: Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
                      case 1: cout<<"Enter the data to be entered"<<endl;
                              cin>>item;
                              D1.Enque1(item);
                              break;
                      case 2: item=D1.Deque();
                              if(item!=0)
                              cout<<"The data removed is "<<item<<endl;
                              break;
                      case 3: D1.display();
                              break;
                      case 4: cout<<"You are exiting now"<<endl;
                              break;
                      default : cout<<"Invalid choice Try again"<<endl;
                                break;
        };
        }while(choice!=4);
        break;
    case 2:
        do
        {
        cout<<"Enter your choice"<<endl;
        cout<<"1: PUSH the data"<<endl;
        cout<<"2: POP the data"<<endl;
        cout<<"4: Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
                      case 1: cout<<"Enter the data to be entered"<<endl;
                              cin>>item;
                              D1.Enque2(item);
                              break;
                      case 2: item=D1.Deque();
                              if(item!=0)
                              cout<<"The data popped is "<<item<<endl;
                              break;
                      case 3: D1.display();
                              break;
                      case 4: cout<<"You are exiting now"<<endl;
                              break;
                      default : cout<<"Invalid choice"<<endl;
                                break;
        };
        }while(choice!=4);
        break;
    default: cout<<"Invalid choice"<<endl;
             break;
    }    
    system("pause");
    return 0;
}
    
        
    
