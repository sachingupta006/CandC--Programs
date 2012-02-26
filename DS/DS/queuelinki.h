#include<iostream>
using namespace std;
template<class T>
struct node
{
       T data;
       node<T> *next;
};

template<class T>
class queue
{
      private:
      node<T> *front;
      node<T> *rear;
      public:
      queue(){rear=NULL;front=NULL;}
      ~queue(){}
      void enqueue(T);
      T dequeue();
      void display();
};
    
template<class T>
void queue<T>::enqueue(T a)
{
     node<T> *newnode;
     newnode=new node<T>;
     newnode->next=NULL;
     newnode->data=a;
     if(front!=NULL)
     {
        rear->next=newnode;
     }
     else
     {
         front=newnode;
     }
     rear=newnode;
}

template<class T>
T queue<T>::dequeue()
{
     if(front==NULL)
     {
          //          cout<<"queue underflow\n";
                    return -1;
     }
     else
     {
         node<T> *temp;
         temp=front;
         T b;
         b=front->data;
        // cout<<front->data<<endl;
         front=front->next;
         delete temp;
         return b;
     }
}
template<class T>
void queue<T>::display()
{
     node<T> *nodeptr;
     nodeptr=front;
     if(front==NULL)
     {return;}
     else
     {
         while(nodeptr!=NULL)
         {
            cout<<nodeptr->data<<" ";
            nodeptr=nodeptr->next;
         }
         cout<<endl;
     }
}

/*int main()
{
      queue<int> a;
      a.add(1);
      a.add(2);
      a.add(3);
      a.add(4);
      a.display();
      a.del();
      a.display();
      cin.ignore();
      cin.get();
      return 0;
}*/
      
