#include<iostream>
#define frames 50
using namespace std;

struct IPT
{
       int phy_add;
       int p_id;
       struct IPT *next;
       bool valid;
}
struct IPT table[frames];

int pid=0;

void allocate(void);

int main()
{
    for(int i=0;i<frames;i++)
    {
            table[i].valid=0;
    }
    cout<<"You can do the following:"<<endl;
    cout<<"1: Allocate memory"<<endl;
    cout<<"2: De-allocate memory"<<endl;
    int choice;
    cin>>choice;
    switch(choice)
    {
                  case 1: 
                          break;
                  case 2: 
                          break;
                  default: cout<<"Invalid choice"<<endl;
    }
    system("pause");
    return 0;
}
void allocate(void)
{
     cout<<"How many frames need to be allocated"<<endl;
     int no;
     cin>>no;
     pid++;
     if(no<=5)
     {
             for(int i=0;i<no;i++)
             {
                     int j=i%5;
                     while(table[i].valid==0)
                     {
                                    table[i].p_id=pid;
                                         
                     
             
