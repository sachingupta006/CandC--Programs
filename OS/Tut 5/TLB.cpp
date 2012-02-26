# include<iostream>
# include<time.h>
# define size 64                                                            // size of the page 
using namespace std;

struct page                                                                 // a structure containing the frame number and the valid bit
{
	int frame;
	bool valid;
};
struct TLB
{
    int page;
    int frame;
    bool valid;
};
struct TLB buffer[10];  
//int level1= 4                                                                // no of page tables 
//int level2= 8                                                                // no of pages in each table

struct page table1[8],table2[8],table3[8],table4[8];     // the 4 page tables that will contain the actual pages 
struct page* pagetable1[4]={table1,table2,table3,table4};

void find(char* );
int index=0;

int main()
{
	srand(time(NULL));
	int rand_no,frame_no=0;
    for(int i=0;i<8;i++)
	{
     	rand_no=rand()%2;
     	if(rand_no==1)
     	{
     	    table1[i].frame=frame_no;
     	    frame_no++;
     	    table1[i].valid=1;
     	    
     	    table2[i].frame=frame_no;
     	    frame_no++;
     	    table2[i].valid=1;
     	    
     	    table3[i].frame=frame_no;
     	    frame_no++;
     	    table3[i].valid=1;
     	    
     	    table4[i].frame=frame_no;
     	    frame_no++;
     	    table4[i].valid=1;
     	}
        else
        {
              table1[i].valid=0;
              table2[i].valid=0;
              table3[i].valid=0;
              table4[i].valid=0;
        }         
    }    
    for(int i=0;i<10;i++)
    {
            buffer[i].page=0;
            buffer[i].frame=0;         
            buffer[i].valid=false;
    }
    for(int i=0;i<8;i++)
	{
     	cout<<"\t Table1 ["<<i<<"] \t Frame: "<<table1[i].frame<<" \t Valid: "<<table1[i].valid<<endl;         
    }    
    cout<<endl;
    for(int i=0;i<8;i++)
	{
     	cout<<"\t Table2 ["<<i<<"] \t Frame: "<<table2[i].frame<<" \t Valid: "<<table2[i].valid<<endl;         
    }   
    cout<<endl;
    for(int i=0;i<8;i++)
	{
     	cout<<"\t Table3 ["<<i<<"] \t Frame: "<<table3[i].frame<<" \t Valid: "<<table3[i].valid<<endl;         
    } 
    cout<<endl;
    for(int i=0;i<8;i++)
	{
     	cout<<"\t Table4 ["<<i<<"] \t Frame: "<<table4[i].frame<<" \t Valid: "<<table4[i].valid<<endl;         
    } 
    char choice;   
    do
    {
          cout<<endl<<endl<<"Enter the logical address"<<endl;
	      char addr[4];
	      cin>>addr;
	      find(addr);
	      //system("pause");
	      cout<<"Do you want to continue?"<<endl;
	      cin>>choice;
    }while(choice=='Y'||choice=='y');
	system("pause");
	return 0;
}
void find(char* addr)                                                        // function to find the frame number of page address is passed as string
{
	int int_addr=0;
    char x=addr[0];                                                     //first character corresponds to the no. of page table to be searched in 1st table 
	int t1=(int)x;
	t1-=48;
	//cout<<"First bit is"<<t1<<endl;
    if(t1>=4)							   // Since there are a mx of 4 page tables
	{
		cout<<"Invalid address"<<endl;
		return;
	}
	int_addr+=t1*10;
	struct page *temp1=pagetable1[t1];					   // A pointer to the page table which we are trying to acces
	x=addr[1];							   // t2 is the second bit whoch corresponds to the page in the t1 page table
	int t2=(int)x;
	t2-=48;
	//cout<<"Second bit is"<<t2<<endl;
	if(t2>=8)								// since are page tables can contain a mx of 8 pages
	{
		cout<<"Invalid address"<<endl;
		return;
	}
	int_addr+=t2;
	if(temp1[t2].valid==0)
	{
		cout<<"The required page is in the disk"<<endl;
	}
	x=addr[2];							// x and x1 give the offset from the starting address
	int t3=(int)x -48;
	char x1=addr[3];
	int t4=(int)x1;
	t4-=48;
	int offset=t3*10+t4;
	if(offset>=size)
	{
		cout<<"The address exceeds the size of a page"<<endl;
		return;
	}
	//int_addr+=offset;
	for(int i=0;i<10;i++)
	{
            if(buffer[i].page==int_addr && buffer[i].valid==true)
            {
                                        cout<<"TLB Hit"<<endl;
                                        cout<<"The physical address for the logical address is "<<(buffer[i].frame*size+offset)<<endl;
                                        return;
            }
    }
	int frame=temp1[t2].frame;
	int phy_add= frame*size+offset;
	cout<<"TLB Miss"<<endl;
	cout<<"The physical address for the logical address is "<<phy_add<<endl;
	buffer[index].page=int_addr;
	buffer[index].frame=frame;
	buffer[index].valid=true;
	index=(index+1)%10;
	cout<<endl<<"Translation Look Aside Buffer"<<endl;
    for(int i=0;i<10;i++)
    {
            cout<<"\t Page "<<buffer[i].page<<" \t Frame: "<<buffer[i].frame<<" \t Valid: "<<buffer[i].valid<<endl; 
    }
	return ;
}

