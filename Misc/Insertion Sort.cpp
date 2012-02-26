#inlcude <iostream>
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
    int min=a[0];
    for(i=0;i<5;i++)
    {
                    for(int j=i;j<5;j++)
                    {
                            if(min<a[j])
                            swap(a[j],min);
                    }
                    swap(min,a[j-1]);
                    min=a[j];
    }
    i=0;
    cout<<"The sorted array is"<<endl;
    while(i!=5)
    {
               cout<<"-"<<a[i++];
    };               
    system("pause");
    return 0;
}
                      
