#include<iostream>
#include<time.h>
#include<stdlib.h>
#define n 500
using namespace std;
int main()
{
    //double time=0.0;
    //int i=1;
    //while(i<=5)
    //{         
    //i++;
    clock_t start = clock();
    int matrix[n][n];
    int matrix_mul[n][n];
    int i,j;
        for(i=0;i<n;i++)
    {
            for(j=0;j<n;j++)
            {
                    matrix[i][j]=rand()%100;
            }
    }
    for(j=0;j<n;j++)
    {
                    for(i=0;i<n;i++)
                    {
                                    int sum=0;
                                    for(int k=0;k<n;k++)
                                    {
                                            sum+=matrix[i][k]+matrix[k][j];
                                    }
                                    matrix_mul[i][j]=sum;
                    }
    }                   
    cout<<"Mutipling matrix"<<endl;
    /*for(i=0;i<n;i++)
    {
            for(j=0;j<n;j++)
            {
                    cout<<matrix_mul[i][j]<<" ";
            }
            cout<<endl;
    }*/
    
    /*time+=((double)clock() - start) / CLOCKS_PER_SEC;
    cout<<"======"<<time<<endl;
    }*/
    cout<<endl<<"Time elapsed: "<<((double)clock() - start) / CLOCKS_PER_SEC;
    system("pause");
    return 0;
}
