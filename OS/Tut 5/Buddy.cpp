#include<iostream>
#include<math.h>
#define min 4
#define max 64
using namespace std;        
void find(int *,int *,int,int);
void display(int *,int *,int);
int main()
{
    int i=0;
    /*cout<<"Enter the minimum size of the heap"<<endl;
    int min;
    cin>>min;
    cout<<"Enter the maximum size"<<endl;
    int max;
    cin>>max;*/
    int count=0;
    int temp=max;
    while(temp!=min)
    {
               count++;
               temp/=2;
    }
    count++;
    //cout<<count<<endl;
    int heap[10][count];
    int allocated[10][count];
    for(int m=0;m<10;m++)
    {
            for(int n=0;n<count;n++)
            {
                    heap[m][n]=0;
                    allocated[m][n]=0;
            }
    }
    cout<<"Enter your choice.";
    cout<<"Enter 0 to EXIT"<<endl<<endl;
    cout<<"You can do the following operations"<<endl<<endl;
    cout<<"1: Create a new binary buddy system"<<endl;
    cout<<"2: Allocate memory"<<endl;
    cout<<"3: De allocate memory"<<endl;
    cout<<"4: Merge buddy system"<<endl;
    int choice;
    cin>>choice;
    int index,size,k,l,index2;
    while(choice!=0)
    {
    switch(choice)
    {
                  case 1:
                       temp=min;
                       for(int j=0;j<count;j++)
                       {
                               cout<<temp<<" size block:"<<endl;
                               int no;
                               cin>>no;
                               heap[i][j]=no;
                               temp*=2;
                       }
                       cout<<"Created a binary buddy system heap["<<i<<"]"<<endl;
                       cout<<endl<<"\t\tHeap["<<i<<"]"<<endl;
                       display(heap[i],allocated[i],count);
                       i++;
                       break;
                  case 2: 
                       cout<<"Enter the index of the buddy system"<<endl;
                       cin>>index;
                       cout<<"Enter the size of memory to be allocated"<<endl;
                       cin>>size;
                       l=min;
                       for(k=0;k<count;k++)
                       {
                              if(l<size)
                              {
                                        l*=2;
                                        continue;           
                              }
                              else if(l==size)
                              {
                                   if(heap[index][k]!=0)
                                   {
                                                        heap[index][k]--;
                                                        allocated[index][k]++;
                                                        cout<<"Memory Allocated"<<endl;
                                                        cout<<endl<<"\t\tHeap["<<index<<"]"<<endl;
                                                        display(heap[index],allocated[index],count);
                                   }
                                   else
                                   {
                                       cout<<endl<<"\t\tHeap["<<index<<"]"<<endl;
                                       find(heap[index],allocated[index],k,count);
                                   }
                                   break;
                              }
                              else 
                              {
                                   if(heap[index][k]!=0)
                                   {
                                                        heap[index][k]--;
                                                        allocated[index][k]++;
                                                        cout<<"Memory Allocated"<<endl;
                                                        cout<<endl<<"\t\tHeap["<<index<<"]"<<endl;
                                                        display(heap[index],allocated[index],count);
                                   }
                                   else
                                   {
                                       cout<<"\t\tHeap["<<index<<"]"<<endl;
                                       find(heap[index],allocated[index],k,count);
                                   }
                                   break;
                              }
                              l*=2;
                       }
                       if(k==count)
                       cout<<"Could not allocate memory"<<endl;
                       break;
                  case 3:
                       cout<<"Enter the index of the buddy system"<<endl;
                       cin>>index;
                       cout<<"Enter the memory block size to be removed"<<endl;
                       cin>>size;
                       k;
                       for(k=0;k<count;k++)
                       {
                               if(size==pow(2,(k+2)))
                               {
                                                    if(allocated[index][k]>=1)
                                                    {
                                                                              allocated[index][k]--;
                                                                              heap[index][k]++;
                                                                              cout<<"Memory De-allocated"<<endl;
                                                                              cout<<endl<<"\t\tHeap["<<index<<"]"<<endl;
                                                                              break;                                                                              
                                                    }
                                                    else
                                                    cout<<"Memory cannot be de-allocated"<<endl;
                               }
                       }
                       if(k==count)
                       cout<<"Memory cannot be de-allocated"<<endl;
                       break;
                  case 4: cout<<"Enter the two indices of the buddy systems"<<endl;
                          cin>>index;
                          cin>>index2;
                          for(int k=0;k<count;k++)
                          {
                                  heap[index][k]+=heap[index2][k];
                                  heap[index2][k]=0;
                                  allocated[index][k]+=allocated[index2][k];
                                  allocated[index2][k]=0;
                          }
                          break;
                  default: 
                           cout<<"Invalid Operation. Try again"<<endl;
                           break;
    }
    cout<<"Enter choice"<<endl;
    cin>>choice;
    }
    system("pause");
    return 0;
}
void find(int *heap,int *allocated,int i,int count)
{
     int initial=i,j;
     i++;
     for(j=i;j<count;j++)
     {
             if(heap[j]>=1)
             {
                           heap[j]--;
                           for(int k=j-1;k>=initial;k--)
                           {
                                   heap[k]++;
                           }
                           break;
             }
     }
     if(j==count)
     cout<<"Memory could not be allocated"<<endl;
     else
     {
         allocated[initial]++;
         cout<<"Allocated a memory of "<<pow(2,(initial+2))<<endl;
         display(heap,allocated,count);
     }
}
void display(int *heap,int *allocated,int count)
{
     cout<<"Block "<<"\tCurrent \t Allocated"<<endl;
     for(int k=0;k<count;k++)
     {
             cout<<pow(2,(k+2))<<"\t"<<heap[k] <<"\t\t"<<allocated[k]<<endl;
     }
}
                          
                                                                              
                                                    
                                   
                                   
                                   
                                   
                                              
                       
                       
