#include <iostream>
using namespace std;
bool isLeapYear(int y)
{
     if((y%4==0)&&((y%100!=0)||(y%400==0)))
     return true;
     else 
     return false;
     
}
int main()
{
    cout<<"Enter the date"<<endl;
    int day,month,year;
    a: cout<<"Day:";
    cin>>day;
    if(day<1)
    {
             cout<<"Enter the date again it cannot be less than 1"<<endl;
             goto a;
    }
    if(day>31)
    {
              cout<<"Enter the date again it cannot be greater than 31"<<endl;
             goto a;
    }
    b: cout<<"Month:";
    cin>>month;
    if(month<1)
    {
             cout<<"Enter the month again it cannot be less than 1"<<endl;
             goto b;
    }
    if(month>12)
    {
             cout<<"Enter the month again it cannot be greater than 12"<<endl;
             goto b;
    }    
    if(month==2&&day>29)
    {
                        cout<<"Feruary cannoot have more than 29 days. Enter the date again"<<endl;
                        goto a;
    }
    cout<<"Year:";
    cin>>year;
    if(month==2||month==4||month==6||month==9||month==11)
    {
         if(day==31)
         {
                    cout<<"Thos month cannot have 31 days Date entered is invalid"<<endl;
                    cout<<"Enter the date again"<<endl;
                    goto a;
         }
    }
    if(month==2)
    {
                if(isLeapYear(year)==false&&day==29)
                {
                                                    cout<<"It is not a leap year and february cannot have 29 days"<<endl;
                                                    cout<<"enter the date again"<<endl;
                                                    goto a;
                }
    }
    cout<<"The date entered is "<<endl;
    if(day%10==0)
    cout<<"0"<<day;
    else
    cout<<day;
    if(month%10==0)
    cout<<"/0"<<month<<"/"<<year;
    else
    cout<<"/"<<month<<"/"<<year;
    cout<<endl;
    char *mn;
    switch(month)
    {
                  case 1: mn="January";
                          break;
                  case 2: mn="February";
                          break;
                  case 3: mn="March";
                          break;
                  case 4: mn="April";
                          break;
                  case 5: mn="May";
                          break;
                  case 6: mn="June";
                          break;
                  case 7: mn="July";
                          break;
                  case 8: mn="August";
                          break;
                  case 9: mn="September";
                          break;
                  case 10: mn="October";
                           break;
                  case 11: mn="November";
                           break;
                  case 12: mn="Dcember";
                           break;
                  default : cout<<"Invalid month"<<endl;
    }
    cout<<"The date as enterd in other format is"<<endl;
    cout<<mn<<" "<<day<<", "<<year<<endl;
    system("pause");
    return 0;
}
