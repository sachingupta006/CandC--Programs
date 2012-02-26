#include<iostream>
#include<time.h>
using namespace std;
void johnson(int *,int *,int *,int);
void adjust (int *,int ,int);
int main()
{
    cout<<"Enter the number of jobs "<<endl;
    cout<<"Enter the number of machines"<<endl;
    int n,m;
    cin>>n>>m;
    int matrix[n][m];
    srand (time(NULL));
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<m;j++)
            {
                    matrix[i][j]=rand()%50;
            }
    }
    int p=m-1,k;
    int *theta[p];
    int *temp2[p];
    int *temp1[p];
    for(int k=0;k<m-1;k++)
    {
            theta[k]=new int[n];
            temp1[k]=new int[n];
            temp2[k]=new int[n];
            for(int i=0;i<=n;i++)
            {
                    int temp_1=0;
                    for(int j=0;j<k;j++)
                    {
                            temp_1+=matrix[i][j];
                    }
                    temp1[i]=temp_1;
                    int temp_2;
                    for(int j=p-k;j<m;j++)
                    {
                            temp_2+=matrix[i][j];
                    }
                    temp2[i]=temp_2;
            }
            johnson(theta[k],temp1[k],temp2[k],n);
    }
    system("pause");
    return 0;
}
void johnson(int *a,int *b,int *c,int n)
{
     int *t1=new int[n];
     int *t2=new int[n];
     int min1=b[0],min2=c[0];
     int *index1=new int;
     int *index2=new int;
     int j=n-1,k=0;
     do
     {
         for(int i=0;i<n;i++)
         {
           if(min1<b[i])
           {
                        min1=b[i];  
                        index1=i;
           }
           if(min2<c[i])
           {
                        min2=c[i];  
                        index2=i;
           }
         }
         if(min1<min2)
         {
                      t1[j--]=index1;
                      adjust(b,index1,n);
                      adjust(c,index1,n);
                      n--;
         }
         else
         {
             t2[k++]=index2;
             adjust(b,index1,n);
             adjust(c,index1,n);
             n--;
         }
     }while(n>0)
     int *final=new int;
     final=0;  
     for(int i=j+1;i<n;i++)
     {
                 a[final++]=t1[i];
     }
     for(int i=0;i<k;i++)
     {
                        a[final++]=t2[i];
     }
     delete [] t1,[] t2,index1,index2,final;
     return;
}
void adjust (int *array,int start,int end)
{
     if(start==(end-1))
     return;
     for(int i=start;i<end-1;i++)
     {
             array[i]=array[i+1];
     }
}
 
