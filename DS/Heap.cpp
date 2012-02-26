#include <iostream>
using namespace std;
template<class T>
class Heap
{
    private:
        T *a;
        int size;
    public:
            Heap(int n)
            {
                size=n;
                a=new T[n+1];
            }
            ~Heap()
            {
                delete a;
            }
            void inputArray();
            void makeHeap();
            void heapify(int ,int );
            void heapsort();
            void output();
};
int main()
{
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    Heap<int> H(n);
    H.inputArray();
    cout<<endl<<"The entered array is :"<<endl;
    H.output();
    H.heapsort();
    cout<<"Sorted array is:"<<endl;
    H.output();
    system("pause");
    return 0;
}        
template<class T>
void Heap<T>::inputArray()
{
     cout<<"Enter "<<size<<"elements of array"<<endl;
     for(int i=1;i<=size;i++)
     {
             cin>>a[i];
     }
}
template<class T>
void Heap<T>::makeHeap()
{
     int i,index;
     index=size/2;
     for(i=index;i>=1;i--)
     {
                          heapify(i,size);
     }
}
template<class T>
void Heap<T>::heapify(int ele,int size)
{
     int index,lc,rc,min,temp;
     lc=2*ele;
     rc=2*ele+1;
     if(lc<=size)
     {
                 min=a[lc];
                 index=lc;
                 if(rc<=size)
                 {
                    if(a[rc]<min)
                    {
                        min=a[rc];
                        index=rc;
                    }
                 }
                 if(a[ele]>a[index])
                 {
                    temp=a[ele];
                    a[ele]=a[index];
                    a[index]=temp;
                    heapify(index,size);
                 }
     }
}
template<class T>
void Heap<T>::heapsort()
{
     int i,temp;
     makeHeap();
     for(i=size;i>1;i--)
     {
                        temp=a[1];
                        a[1]=a[i];
                        a[i]=temp;
                        heapify(1,i-1);
     }
}
template<class T>
void Heap<T>::output()
{
     int i;
     for(i=1;i<=size;i++)
     {
                         cout<<a[i]<<"-";
     }
     cout<<endl;
}
/*void Heap :: swap (int &a, int &b)
{
     int temp;
     temp=a;
     a=b;
     b=temp;
} 
void Heap:: minHeapify(int a[], int i,int length)
{
    int r,l;
    r=right(i);
    l=left(i);
    if(l>length)
    return;
    int smallest;
    if(a[l]<a[i]&&l<=length)
    smallest=l;
    else
    smallest =i;
    if(a[r]<a[i]&&r<=length)
    smallest=r;
    if(smallest!=i)
    swap(a[i],a[smallest]);
    minHeapify(a,smallest,length);
}   
void Heap:: makeHeap(int a[],int length)
{
    int j=length/2;
    for(int k=j;k>=0;k--)
    {
        minHeapify(a,k,length);
    }
}    
int Heap:: left (int i)
{
    return (2*i +1);
}
int Heap:: right (int i)
{
    return (2*i+2);
}
int Heap :: parent(int i)
{
    return i/2;
}*/
