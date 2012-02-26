#include<iostream>
using namespace std;
void hReady(void);
void oReady(void);
void makeWater(void);
int h=0;
int o=0;
int h1=0;
int o1=0;
int index=0;
int water=0;
char atoms[10];
int main()
{
    cout<<"Enter 10 atoms: 1-Hydrogen 0-Oxygen"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>atoms[i];
    }    
    do
    {
         cout<<endl;
         if(atoms[index]=='1')
         hReady();
         else
         oReady();
    }while(index<=9); 
    if(o>0)
    cout<<o<<" Oxygen atoms have been left unused"<<endl;
    if(h>0)
    cout<<h<<" Hydrogen atoms have been left unused"<<endl;                       
    cout<<endl<<endl;
    system("pause");
    return 0;
}    
void hReady(void)
{
    if(index>9)
    return;
    h++;
    index++;
    if(h>=2&&o>=1)
    makeWater();
    if(h1>0)
    {
        h1--;
        cout<<"One H atom used"<<endl;
        return;
    }    
    if(atoms[index]=='1')
    hReady();
    else
    oReady();
    if(h1>0)
    {
                h1--;
                cout<<"One H atom used"<<endl;
                return;
    } 
    return;        
}
void oReady(void)
{
    o++;
    index++;
    if(h>=2&&o>=1)
    makeWater();
    if(index>9)
    return;
    if(o1>0)
    {
        o1--;
        cout<<"One O atom used"<<endl;
        return;
    }    
    if(atoms[index]=='1')
    hReady();
    else
    oReady();
    if(o1>0)
    {
        o1--;
        cout<<"One O atom used"<<endl;
        return;
    }
    return;
}
void makeWater(void)
{
    cout<<endl;
    water++;
    h--;
    h--;
    o--;
    h1=h1+2;
    o1=o1+1;
    cout<<water<<" molecule of water made."<<endl;
    return;
}    
    
