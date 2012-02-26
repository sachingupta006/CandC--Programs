 #include <iostream>
 #include <string.h>
 using namespace std;
bool testPalindrome (char [], int, int);

int main()
{
    char str[24],copy[24];
    cout<<"Enter a string to be tested whether its palindrome or not"<<endl;
    gets(str);
    int l=strlen(str);
    int i=0;
    for(int j=0;j<l;j++)
    {
            if(str[j]>='a'&&str[j]<='z'||str[j]>='A'&&str[j]<='Z'||str[j]>='0'&&str[j]<='9')
            copy[i++]=str[j];
    }
    copy[i]='\0';
    cout<<"the stirng entered without spaces is "<<endl;        
    for(int k=0;k<i;k++)
    {
            cout<<copy[k];
    }
    cout<<endl;
    int s=0;
    if(testPalindrome(copy,i-1,s))
    cout<<"The string eneterd is palindrome"<<endl;
    else 
    cout<<"The string entered is not palindrome"<<endl;
    system("pause");
    return 0;
}
bool testPalindrome (char a[], int len, int start)
{
     static int check= len;
     if(a[len]!= a[start])
     return false;
     if (start==check)
     return true;
     else 
     testPalindrome(a,len-1,start+1);
} 
 
