#include<iostream>
#include<vector>
#include<cmath>
#include<time.h>

#define PARENT(i) (i+1)/2 - 1
#define LEFT(i) 2*(i+1) - 1
#define RIGHT(i) 2*(i+1)
#define swap(a,b) (a)^=(b)^=(a)^=(b)

using namespace std;

template <class T>
class Heap
{
	private:
		vector<T> A;
		
	public:
		
		// This constructor uses 
		Heap(int len)
		{
			for(int i=0;i<len;i++)
				A.push_back(rand()%50);
				
			buildHeap();
		}
		
		//This constructor takes an array and it's length and uses them to make a heap
		Heap(T* array,int len)
		{
			A.insert (A.begin(), array, array+len);
			buildHeap();
		}
		void sift_down(int i)
		{
			int size=A.size();
			while(i < size)
			{
				int l = LEFT(i);
				int r = RIGHT(i);
				int largest;
				if(l<size && A[l]>A[i])
					largest=l;
				else
					largest=i;
				if(r<size && A[r]>A[largest])
					largest=r;
				if(largest!=i)
				{
					swap(A[i],A[largest]);
					i=largest;
				}
				else
					break;
			}
		}

		void sift_up(int i)
		{
			 while(i>0)
			 {
				if( PARENT(i) >= 0 && A[PARENT(i)] < A[i] )
				{
					swap(A[i], A[PARENT(i)]);
					i = PARENT(i);
				}
				else
					break;
			  }
		}

		void buildHeap()
		{
			int start = (int)floor((double)(A.size()-1)/2);
			for(int i=start;i>=0;i--)
				sift_down(i);
		}
		
		void display()
		{
			for(int i=0;i < A.size();i++)
				cout<<A[i]<<" ";
			cout<<endl;
		}
		
		void insertElement (T x)
		{
			A.push_back(x);
			sift_up(A.size()-1);
		}
		
		void showTop()
		{
			cout<<"Top element is "<<A[0]<<endl;
		}
		
		void removeTopElement()
		{
			swap(A[0],A[A.size()-1]);
			A.pop_back();
			sift_down(0);
		}
};

int main()
{
	srand(time(NULL));
	cout<<"Enter the initial length of the Heap. "<<endl;
	int len;
	cin>>len;	
	int array[len];
	
	// Here you can either call the constructor that takes an arrray 
	// or you can just pass the length and a random set of numbers
	// of that length will be created
	for(int i=0;i<len;i++)
		array[i]=(rand()%50);
	
	Heap<int> H1(array,len);	
	
	cout<<"Your heap is "<<endl;
	H1.display();
	
	int choice;
	cout<<"You have the following choices:"<<endl;
	cout<<"1: Add element"<<endl;
	cout<<"2: Check Maximum"<<endl;
	cout<<"3: Remove Maximum"<<endl;
	cout<<"Enter 0 to stop"<<endl;
	cin>>choice;
	do
	{
		switch(choice)
		{	
			case 1: 
				cout<<"Enter the element"<<endl;
				int ele;
				cin>>ele;
				H1.insertElement(ele);
				H1.display();
				break;
			
			case 2: 
				H1.showTop();
				break;
				
			case 3:
				H1.removeTopElement();
				H1.display();
				break;
				
			default:
				cout<<"Invalid choice"<<endl;
				break;
		}
	cout<<"Enter choice"<<endl;
	cin>>choice;
	}while(choice);
	
	system("pause");
	return 0;
}
