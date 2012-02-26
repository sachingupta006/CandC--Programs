# include<iostream>
using namespace std;
int count_c=1;
int countCat(int months,int check)
{
    if(months==0)
    return 0;
    if(months<=check)
    {
                 count_c++;
                 count_c+=countCat(months,months-3);
    }
    --months;
    return 0+countCat(months,check);
}
int countcat(int months,int check)
{
    if(months==0)
    return count_c;
    if(months<=check)
    {
                 count_c++;
                 count_c+=countCat(months,months-3);
    }
    --months;
    return 0+countcat(months,check);
}
int main()
{
    a: cout<<"Do you want to enter months or years?"<<endl;
    char choice;
    cin>>choice;
    switch(choice)
    {
                  case 'm':    
                               cout<<"Enter the no. of months"<<endl;
                               int m;
                               cin>>m;
                               cout<<"The total no. of cats are "<<countcat(m,m-3)<<endl;
                               break;
                  case 'y': 
                            cout<<"For how many years do you want to calculate the no. of cats?"<<endl;
                            int y;
                            cin>>y;
                            cout<<"The total no. of cats are "<<countcat(y*12,y*12-3)<<endl;
                            break;
                  default: cout<<"You must enter either m(months) or y(years)"<<endl;
                           goto a;
                           
    };
    system("pause");
    return 0;
}
