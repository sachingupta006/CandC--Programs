#include<iostream>
using namespace std;
void swap(int &a, int &b)
{
         int temp;
         temp=a;
         a=b;
         b= temp;
}        
class array
{
      public:
             int a[100],pos,number;
             void del(int a[],int,int &);
             void insert(int a[],int,int,int &);
             void combine(int a[], int b[],int c[],int,int);
};
int main()
{
    array A;
    cout<<"How man no.s do you want to enter?"<<endl;
    cout<<"You cannot enter more than 100 numbers"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the no.s in the array"<<endl;
    for(int i=0;i<n;i++)
    {
            cin>>A.a[i];
    }
    cout<<"You have the following options"<<endl;
    cout<<" 1: Insert a number"<<endl;
    cout<<" 2: Delete a no."<<endl;
    cout<<" 3: Tranverse the array"<<endl;
    cout<<" 4: Join 2 arrays"<<endl;
    cout<<" 5: Exit"<<endl;
    int choice;
    do
    {
            cout<<"Enter your choice"<<endl;
            cin>>choice;
            switch(choice)
            {
                           case 1: if(n==100)
                                   cout<<"The array is full"<<endl;
                                   cout<<"Enter the number to be inserted"<<endl; 
                                   cin>>A.pos;
                                   cout<<"Enter the position where you want to insert"<<endl;
                                   cin>>A.number;
                                   A.insert(A.a,A.pos,A.number,n);
                                   break;
                           
                           case 2: cout<<"Enter the position of the no. you want to delete"<<endl;
                                   cin>>A.pos;
                                   A.del(A.a,A.pos-1,n);
                                   break;
                                   
                           case 3: cout<<"The array is"<<endl;
                                   for(int i=0;i<n;i++)
                                   {
                                           cout<<A.a[i]<<endl;
                                   }
                                   break;
                            
                           case 4: cout<<"Enter the no. of elements of the 1st array"<<endl;
                                   int a1;
                                   cin>>a1;
                                   int ar1[a1];
                                   cout<<"Enter the no. of elements of array 2"<<endl;
                                   int a2;
                                   cin>>a2;
                                   int ar2[a2];
                                   cout<<"Enter the elements of array 1"<<endl;
                                   for(int k=0;k<a1;k++)
                                   {
                                           cin>>ar1[k];
                                   }
                                   cout<<"Enter the elements of array 2"<<endl;
                                   for(int k=0;k<a2;k++)
                                   {
                                           cin>>ar2[k];
                                   }
                                   cout<<"How many extra elements do you want to keep in the combined array"<<endl;
                                   int delta;
                                   cin>>delta;
                                   int ar3[a1+a2+delta];
                                   A.combine(ar1,ar2,ar3,a1,a2);
                                   break;  
                    default:       cout<<"Invalid choice"<<endl;
                                
            }
    }while(choice!=5);                            
    system("pause");
    return 0;
}
void array::del(int a[], int b, int &c)
{
                  int j;
                  for(j=b;j<c;j++)
                  {
                                  a[j]=a[j+1];
                  }
                  c--;
                  cout<<"New array: "<<endl;
                  for(j=0;j<c;j++)
                  {
                                  cout<<a[j]<<endl;
                  }
}
void array:: insert(int a[], int l,int b,int &c)
{
     int i;
     for(i=c;i>l;i--)
     {
                     a[i]=a[i-1];
     }
     a[i]=b;
     c=c+1;  
     cout<<"New array: "<<endl;
     for(i=0;i<c;i++)
     {
     cout<<a[i]<<endl;
     }            
}
void array:: combine(int a[],int b[],int c[],int l1, int l2)
{
                int a3=0;
                int i,j;
                for(i=0;i<l1;i++)
                {
                        for(j=0;j<l1-i;j++)
                        {
                                if(a[j]>a[j+1])
                                swap(a[j],a[j+1]);
                        }
                }
                for(i=0;i<l2;i++)
                {
                        for(j=0;j<l2-i;j++)
                        {
                                if(a[j]>a[j+1])
                                swap(a[j],a[j+1]);
                        }
                }
                i=0,j=0;
                while((i<l2)&&(j<l2))
                {
                      if(a[i]<=b[j])               
                      c[a3]=a[i++];
                      else
                      c[a3]=b[j++];
                      a3++;
                }
                while(i<l1)
                {
                       c[a3++]=a[i++];
                }
                while(j<l2)
                {
                     c[a3++]=b[j++];
                }
                cout<<"The array after merging is "<<endl;
                for(int l=0;l<a3;l++)
                {
                        cout<<c[l]<<endl;
                }
     }
                
                        
                                

    
