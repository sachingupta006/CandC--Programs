#include<iostream>
#include<time.h>
#define frames 50
#define pageSize 10
using namespace std;
int no_frames=0;

struct IPT
{
       int phy_add;
       int p_id;
       //struct IPT *next;
       bool valid;
};
struct IPT table[frames];

int pid=0;

void allocate(void);
void deallocate(void);
void randomAllocate(void);
void search(int, int);

int main()
{
    
    srand (time(NULL));
    for(int i=0;i<frames;i++)
    {
            table[i].valid=0;
            table[i].p_id=0;
            table[i].phy_add=i;
    }
    cout<<"You can do the following:"<<endl;
    cout<<"1: Allocate memory"<<endl;
    cout<<"2: De-allocate memory"<<endl;
    cout<<"3: Randomly create 2 processes"<<endl;
    cout<<"4: Search for a address"<<endl;
    cout<<"Enter a 0 when you no more allocation is to be done"<<endl;
    int choice;
    cin>>choice;
    while(choice!=0)
    {
                    switch(choice)
                    {
                                  case 1: allocate();
                                          break;
                                  case 2: deallocate();
                                          break;
                                  case 3: randomAllocate();
                                          break;
                                  case 4: cout<<"Enter the process id"<<endl;
                                          int p;
                                          cin>>p;
                                          cout<<"Enter the page number"<<endl;
                                          int page_no;
                                          cin>>page_no;
                                          search(p,page_no);
                                          break;
                                  default: cout<<"Invalid choice"<<endl;
                    }
                    cin>>choice;
    }
    cout<<"Exiting"<<endl;
    system("pause");
    return 0;
}
void allocate(void)
{
     int no;
     cout<<"How many frames need to be allocated"<<endl;
     cin>>no;
     if(no>10)
     {
              cout<<"Cannot allocate more than 10 frames. \nAllocating 10 frames"<<endl;
              no=10;
     }
     pid++;
     if(no<=5)
     {
             for(int i=0;i<no;i++)
             {
                     for(int j=i%5;j<frames;j=j+5)
                     {
                             if(table[j].valid==0)
                             {
                                          table[j].p_id=pid;
                                          table[j].valid=1;
                                          no_frames++;
                             }
                             if(no_frames==frames)
                             {
                                    cout<<"No more frames can be allocated"<<endl;
                                    return;
                             }
                     }
             }
             cout<<"Allocated "<<no<<" number of frames to process "<<pid<<endl;
     }
     else
     {
         for(int i=0;i<5;i++)
         {
              for(int j=i%5;j<frames;j=j+5)
              {
                     if(table[j].valid==0)
                     {
                                          table[j].p_id=pid;
                                          table[j].valid=1;
                                          no_frames++;
                     }
                     if(no_frames=frames)
                     {
                                    cout<<"No more frames can be allocated"<<endl;
                                    return;
                     }
                     
              }
         }   
         for(int i=5;i<no;i++)
         {
                 for(int j=i%10;j<frames;j=j+10)
                 {
                     if(table[j].valid==0)
                     {
                                          table[j].p_id=pid;
                                          table[j].valid=1;
                                          no_frames++;
                     }
                     if(no_frames==frames)
                     {
                                    cout<<"No more frames can be allocated"<<endl;
                                    return;
                     }
                 }
         }  
         cout<<"Allocated "<<no<<" number of frames to process "<<pid<<endl; 
     }
     
}
void deallocate(void)         
{
     cout<<"Enter the process id"<<endl;
     int p;
     cin>>p;
     cout<<"Enter the page no"<<endl;
     int pn;
     cin>>pn;
     if(pn<=5)
     {
              for(int j=pn-1;j<frames;j=j+5)
              {
                  if(table[j].p_id==p)
                  {
                                      table[j].valid=0;
                                      no_frames--;
                  }
                  if(table[j].p_id==0 && table[j].valid==0)
                  {
                                      cout<<"Page cannot be de-allocated as it does not exist"<<endl;
                  }
              }
     }
     else
     {
         for(int j=pn-1;j<frames;j=j+10)
         {
                 if(table[j].p_id==p)
                 {
                                      table[j].valid=0;
                                      no_frames--;
                 }
                 if(table[j].p_id==0 && table[j].valid==0)
                 {
                                      cout<<"Page cannot be de-allocated as it does not exist"<<endl;
                 }
         }
     }
} 
void randomAllocate(void)
{
     int no=rand()%5;
     if(no==0)
     no=no+3;
     pid++;
     for(int i=0;i<no;i++)
     {
             int j=i%5;
             while(table[j].valid!=0)
             {
                    j=j+5;
             }
             table[j].p_id=pid;
             table[j].phy_add=i+1;
             table[j].valid=1;
             no_frames++;
             if(no_frames==frames)
             cout<<"The process could not be completed all the frames"<<endl;
     }
     cout<<"Created a process "<<pid<<" with "<<no<<" number of pages"<<endl;
     no=rand()%10;
     if(no==0)
     no+=6;
     pid++;       
     for(int i=0;i<no;i++)
     {
             int j=i%10;
             while(table[j].valid!=0)
             {
                    j=j+10;
             }
             table[j].p_id=pid;
             table[j].phy_add=i+1;
             table[j].valid=1;
             no_frames++;
             if(no_frames==frames)
             cout<<"The process could not be completed all the frames"<<endl;
     }
     cout<<"Created a process "<<pid<<" with "<<no<<" number of pages"<<endl;
}               
void search (int pid,int page_no)
{
     cout<<"Enter the offset"<<endl;
     int offset;
     cin>>offset;
     int i; 
     if(page_no<=5)
     {
                   i=page_no%5;
                   for(int j=i-1;j<frames;j=j+5)
                   {
                           if(table[j].p_id==0)
                           {
                                               cout<<"Page Fault"<<endl;
                                               return;
                           }
                           else if(table[j].p_id==pid)
                           {
                                                 if(table[j].valid==0)
                                                 {
                                                                      cout<<"The page has been removed"<<endl;
                                                                      cout<<"Page fault"<<endl;
                                                                      return;
                                                 }
                                                 else
                                                 {
                                                     cout<<"The physical address of the page is "<<(table[j].phy_add*10)+offset<<endl;
                                                     return;
                                                 }
                           }
                           else{}
                   }
     }
     else
     {
         i=page_no%10;
         for(int j=i-1;j<frames;j=j+5)
         {
                      if(table[j].p_id==0)
                      cout<<"Page Fault"<<endl;
                      else if(table[j].p_id==pid)
                      {
                                       if(table[j].valid==0)
                                       {
                                                            cout<<"The page has been removed"<<endl;
                                                            cout<<"Page fault"<<endl;
                                       }
                                       else
                                       {
                                                cout<<"The physical address of the page is "<<table[j].phy_add<<endl;
                                       }
                       }
                       else{}
         }
     }
} 
                   
             
