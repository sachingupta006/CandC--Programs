# include<iostream>
using namespace std;
void swap(int &a, int &b)
{
     int swapper=a;
     a=b;
     b=swapper;
}     
int main()
{
    cout<<"Enter 5 nos."<<endl;
    int a[5];
    int i=0;
    while(i!=5)
    {
               cin>>a[i++];
    };
    int j,temp;
    for(i=1;i<5;i++)
    {
                    temp=a[i];
                    j=i-1;
                    while(temp<a[j]&&j>=0)
                    {
                                          a[j+1]=a[j];
                                          j=j-1;
                    }
                    a[j+1]=temp;
    }                
    cout<<"The sorted array is"<<endl;
    i=0;
    while(i!=5)
    {
               cout<<"-"<<a[i++];
    };               
    cout<<endl;
    system("pause");
    return 0;
}
                      
