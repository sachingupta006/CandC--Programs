#include<iostream>
using namespace std;
struct node
{
    int direc;
    int index;
    node *next;
};
class Queue
{
    private:
        node *head,*end;
    public:
        int count;
        Queue()
        {
            head=NULL;
            end=NULL;
            count =0;
        }
        void Enqueue(int x, int y)
        {
            node *temp=new node;
            temp->direc=x;
            temp->index=y;
            temp->next=NULL;
            count++;
            if(head==NULL)
            {
                head=temp;
                end=temp;
            }    
            else
            {
                end->next=temp;
                end=temp;
            }
        }    
        int Dequeue()
        {
            node *temp;
            int value;
            temp=head;
            count--;
            if(temp==NULL)
            {
                cout<<"Queue is already empty"<<endl;
                value= 0;
            }
            else
            {
                head=head->next;
                value=temp->direc;
                delete temp;
            }
            //cout<<"Data Removed"<<endl;
            return value;
        }                   

}Q; 
int direction;
int numberOfCars=0;
int cars[11];
int index=0;
int flag=0;

void oneVehicle (int);
void arriveBridge(int);
void crossBridge(int);
void exitBridge(int);

int main()
{
    cout<<"Enter 11 cars"<<endl;
    for(int i=0;i<11;i++)
    {
        cin>>cars[i];
    }
    oneVehicle(cars[index]); 
    //cout<<"Me bahar aa gaya"<<endl;   
    system("pause");
    return 0;
}

void oneVehicle (int direc)
{
    //cout<<"Entering One vehicle of index"<<index<<endl;
    arriveBridge(direc);
    crossBridge(direc);
    exitBridge(direc);
    //cout<<"Exiting one vehicle of index"<<index<<endl;
    return;
}
       
void arriveBridge(int direc)
{
    
    if(index>10)
    return;
    //cout<<"Entering arrive bridge of index"<<index<<" and direction"<<direc<<endl;
    if(flag==1)
    {
               numberOfCars++;
               flag=0;
               return;
    }
    if(numberOfCars==0)
    {
        direction=direc;
        index++;
        numberOfCars++;
        while(cars[index]!=direction)
        {
                                  //cout<<"Q me dala"<<endl;
                                  Q.Enqueue(cars[index],index);
                                  index++;
                                  if(Q.count==2)
                                  {
                                                flag=1;
                                                //cout<<"Exiting arrive bridge of index"<<index<<" and direction"<<direc<<endl;
                                                return;
                                  }
        }                          
        if(index>11)
        return;
        oneVehicle(cars[index]);
        //cout<<"Exiting arrive bridge of index"<<index<<" and direction"<<direc<<endl;
        return;
    }     
    if(direc==direction&&numberOfCars<3)
    {
        numberOfCars++;
        //cout<<endl<<"No of cars = " <<numberOfCars<<endl;
        index++;
        if(numberOfCars==3)
        {        //cout<<"Exiting arrive bridge of index"<<index<<" and direction"<<direc<<endl;
                return;
        }    
        while(cars[index]!=direction)
        {
                                  Q.Enqueue(cars[index],index);
                                  //cout<<"\n q me dala direction = "<<direc;
                                  index++;
                                  if(Q.count==2)
                                  {
                                      //cout<<"Exiting arrive bridge of index"<<index<<" and direction"<<direc<<endl;
                                      return;
                                  }    
        }                          
        if(index>11)
        return;
        oneVehicle(cars[index]);
        //cout<<"Exiting arrive bridge of index"<<index<<" and direction"<<direc<<endl;
        return;
    }  
}    
void crossBridge(int direc)
{
    //return;
}
void exitBridge(int direc)
{
        //cout<<"Entering exit bridge of index "<<index<<" and direction"<<direc<<endl;
        numberOfCars--;
        cout<<"The cars on the bridge are exiting in direction "<<direc<<endl;
        if(Q.count>0&&numberOfCars==0)
        {
                  flag=1;
                  int di=Q.Dequeue();
                  //cout<<"ghus gaya"<<di<<endl;
                  oneVehicle(di);
        }
        if(numberOfCars==0)
        {
                           if(index>10)
                           {
                                //cout<<"Exiting exit bridge of index "<<index<<" and direction"<<direc<<endl;
                                return;
                           }    
                           else
                           oneVehicle(cars[index]);
        } 
        //cout<<"Exiting exit bridge of index "<<index<<" and direction"<<direc<<endl;
}
        
    

