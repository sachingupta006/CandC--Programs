#include<iostream>
#include<string.h>
using namespace std;
int compare(char a[], char b[])
{
    int l1=strlen(a);
    int l2=strlen(b);
    int l;
    if(a<b)
    l=l1;
    else
    l=l2;
    int i=0;
    for(i=0;i<l;i++)
    {
            if(a[i]!=b[i])
            return (a[i]-b[i]);
            else
            continue;
    }
    if(i==l)
    return 0;
}
void swap( char c[], char d[])
{
     char temp[20];
     int i=0;
     for(i=0;i<strlen(c);i++)
     {
             temp[i]=c[i];
     }
     temp[i]='\0';
     int j=0;
     for(j=0;j<strlen(d);j++)
     {
                             c[j]=d[j];
                             
     }
     c[j]='\0';
     int k=0;
     for(k=0;k<strlen(temp);k++)
     {
                             d[k]=temp[k];
                             
     }
     d[k]='\0';    
}    
void sort (char a[][20], int (*p1)(char a[], char b[]),void (*p2)(char c[], char d[]),int no)
{
     for(int i=0;i<no;i++)
     {
             for(int j=0;j<no-i;j++)
             {
                               if((*p1)(a[j],a[j+1])<0)
                               (*p2)(a[j],a[j+1]);
             }
     }
}
int main()
{
    int n;
    cout<<"How many names do you want to enter?"<<endl;
    cin>>n;
    char names[n][20];
    cout<<"enter the "<<n<<" names"<<endl;
    for(int i=0;i<n;i++)
    {
            cin>>names[i];
    }
    cout<<endl;
    cout<<"The names entered are"<<endl;
    for(int i=0;i<n;i++)
    {
            cout<<names[i]<<endl;
    }
    sort(names,compare,swap,n);
    cout<<"After sorting the names in alphabetical order"<<endl;
    for(int i=n;i>=0;i--)
    {
            cout<<names[i]<<endl;
    }
    system("pause");
    return 0;
}
