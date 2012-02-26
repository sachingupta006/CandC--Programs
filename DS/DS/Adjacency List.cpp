# include<iostream>
using namespace std;
struct nodes
{
       int key;
       struct nodes *next ;
       struct nodes *below;  
}*first=NULL;
typedef struct nodes N;
int n;
class adjList
{
      public:
      void createNodes(int);
      void createEdges(int);
      void addEdge(int,int);
      void RemoveEdge(int,int);
      int edgeExists(int n1, int n2);
};    
int main ()
{
    adjList AL;
    cout<<"*****Creating a graph*****"<<endl;
    cout<<endl<<"How many nodes you want to make?"<<endl;
    cin>>n;
    AL.createNodes(n);
    cout<<"You have now created the vertices"<<endl;
    cout<<endl<<"Now you will make the edges"<<endl;
    for(int i=0;i<n;i++)
    {
            cout<<endl<<"Enter the value to which edges are to be joined"<<endl;
            //cout<<"We will draw its edges"<<endl;
            int value;
            cin>>value;
            AL.createEdges(value);
    }
    cout<<"You have successfully created an adjacenecy list"<<endl;
    system("pause");
    return 0;
}    
void adjList :: createNodes(int a)
{
     for(int i=0;i<a;i++)
     {
             N *vert,*temp;
             vert = new N;
             cout<<"Enter the value of the node"<<endl;
             cin>>vert->key;
             vert->below=NULL;
             vert->next=NULL;
             if(first!=NULL)
                    {
                                  temp->below=vert;
                                  temp=vert;
                    }
                    else
                    {
                                  temp=vert;
                                  first=vert;
                    }
     }
}
void adjList::createEdges(int a)
{
     N *temp;
     int no;
     for(temp=first;temp->below!=NULL;temp=temp->below)
     {
                    if(temp->key==a)
                    break;
     }
     cout<<"How many edges do you want to craete?"<<endl;
     cin>>no;
     for(int i=0;i<no
     ;i++)
     {
             cout<<"Enter the value of other edge"<<endl;
             int check;
             cin>>check;
             N *point;
             point = new N;
             point->key=check;
             point->next=NULL;
             temp->next=point;
             temp=point;
     }

}
void adjList :: addEdge(int n1, int n2)
{
     N *temp;
     for(temp=first;temp->below!=NULL;temp=temp->below)
     {
                    if(temp->key==n1)
                    break;
     }
     while(temp->next!=NULL)
     {
                            temp=temp->next;
     };
     N *vert;
     vert = new N;
     vert->key=n2;
     vert->next=NULL;
     for(temp=first;temp->below!=NULL;temp=temp->below)
     {
                    if(temp->key==n2)
                    break;
     }
     N *vert;
     vert = new N;
     vert->key=n1;
     vert->next=NULL;
}
void adjList :: removeEdge(int n1, int n2)
{
     N *temp,*prev;
     for(temp=first;temp->below!=NULL;temp=temp->below)
     {
                    if(temp->key==n1)
                    break;
     }
     while(temp->next!=NULL)
     {
                            if(temp->key==n2)
                            break;
                            prev=temp;
                            temp=temp->next;
     };                 
     prev->next=temp->next;
     delete temp;
     for(temp=first;temp->below!=NULL;temp=temp->below)
     {
                    if(temp->key==n2)
                    break;
     }
     while(temp->next!=NULL)
     {
                            if(temp->key==n2)
                            break;
                            prev=temp;
                            temp=temp->next;
     };  
     prev->next=temp->next;
     delete temp;
}
int adjList :: edgeExists(int n1, int n2)
{
    N *temp;
    for(temp=first;temp->below!=NULL;temp=temp->below)
     {
                    if(temp->key==n1)
                    break;
     }
     while(temp->next!=NULL)
     {
                            if(temp->key==n2)
                            return 1;
                            temp=temp->next;
     }
     if(temp->next==NULL)
     return 0;
}
                            
    
     
                
     
                         
     
     
                                                  
     


     
             
             
             
                    
                    
     
     
