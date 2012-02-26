# include<iostream>
# include<stdio.h>
# include<conio.h>
# include "ownDS.h"                                  //data structurein which element are added to the end and removed also from the end is used for storing the cells which have more than one opening    
using namespace std;

struct map                                                 //structure used to store the info of a particular cell
{
       int left;
       int top;
       int right;
       int bottom;
};
int nop(map cells[],int pos)                              //number of openings in a particular cell
{
    int i=0;
    if(cells[pos].left==1)
    i++;
    if(cells[pos].top==1)
    i++;
    if(cells[pos].right==1)
    i++;
    if(cells[pos].bottom==1)
    i++;
    return i;                                                  //function returns the number of openings in the cell
}
int main()

{
    int i,j;
    SQueue <int> Q;                                                  
    int row,column;                                           //rows and columns in the maze
    cout<<"Enter the number of rows"<<endl;
    cin>>row;
    cout<<"Enter the number of Columns"<<endl;
    cin>>column;
    int sizeofmaze;                                                      
    sizeofmaze=row*column;                                       //calculating the number of cells
    struct map cell[sizeofmaze];                                  //an array of structure map  
    cout<<"Enter the map of the maze"<<endl;
    for(int i=1;i<=sizeofmaze;i++)
    {
            cin>>cell[i].left;
            cin>>cell[i].top;
            cin>>cell[i].right;
            cin>>cell[i].bottom;
    }//input the map of the maze
    
    int pos=1,flag=0,flag2=0,exitgates=0;                           //initialize cellpos to 1i.e starting
    cell[pos].left=0;
    Q.Enqueue(pos);
    if(cell[pos].right==1)
    {
                          cell[pos].right=0;
                          flag=1;
                          pos=pos+1;
    }
    else
    {
        cell[pos].bottom=0;
        pos=pos+column;
        flag=2;
    }
    do
    {
        do
        {
         if(flag==1)
         cell[pos].left=0;
         else if(flag==2)
         cell[pos].top=0;
         else if(flag==3)
         cell[pos].right=0;
         else if(flag==4)
         cell[pos].bottom=0;
         else                               // just to fill the else codition basically it does nothing
         {
             flag++;
             flag--;
         }
                 
         Q.Enqueue(pos);
         if(cell[pos].left==1)
         {
                          cell[pos].left=0;
                          flag=3;
                          i=(pos-1)/row;
                          j=(pos-1)%column;
                          pos=pos-1;
                          j--;
                          if(j<0)
                          flag2=1;
         }
         else if(cell[pos].top==1)
         {
                          cell[pos].top=0;
                          flag=4;
                          i=(pos-1)/row;
                          j=(pos-1)%column;
                          pos=pos-column;
                          i--;
                          if(i<0)
                          flag2=1;                         
         }
         else if(cell[pos].right==1)
         {
                          cell[pos].right=0;
                          flag=1;
                          i=(pos-1)/row;
                          j=(pos-1)%column;
                          pos=pos+1;
                          j++;
                          if(j>=column)
                          flag2=1;
         }
         else if(cell[pos].bottom==1)
         {
                          cell[pos].bottom=0;
                          flag=2;
                          i=(pos-1)/row;
                          j=(pos-1)%column;
                          pos=pos+column;
                          i++;
                          if(i>=row)
                          flag2=1;
         }
         else
         {
         }
        }while(flag2!=1);
        
        exitgates++;
        cout<<exitgates<<" exit path is"<<endl;
        Q.display();
        flag2=0;
        int check;
        
        do
        {
                pos=Q.Deque();
                check=nop(cell,pos);
                
        }while(check==0&&Q.isEmpty()==0);
        
    }while(Q.isEmpty()==0);
    cout<<"Total number of exit gates are "<<exitgates<<endl;
    system("pause");
    return 0;
}
