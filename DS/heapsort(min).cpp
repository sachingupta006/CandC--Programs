#include<iostream>
using namespace std;
template<class T>
class array
{
    private:
        T *a;
        int size;
        public:
            array(int n)
            {
                size=n;
                a=new T[n+1];
            }
            ~array()
            {
                delete a;
            }
            void inputarray();
            void heapify();
            void reheapifydown(int ,int );
            void heapsort();
            void output();
        };
        template<class T>
        void array<T>::inputarray()
        {
            cout<<"\n enter "<<size<<"elements of array"<<endl;
            for(int i=1;i<=size;i++)
            {
                cin>>a[i];
                
            }
        }
         template<class T>
        void array<T>::heapify()
        {
            int i,index;
            index=size/2;
            for(i=index;i>=1;i--)
            {
                reheapifydown(i,size);
            }
        }
         template<class T>
        void array<T>::reheapifydown(int start,int finish)
        {
            int index,lchild,rchild,min,temp;
            lchild=2*start;
            rchild=2*start+1;
            if(lchild<=finish)
            {
                min=a[lchild];
                index=lchild;
                if(rchild<=finish)
                {
                    if(a[rchild]<min)
                    {
                        min=a[rchild];
                        index=rchild;
                    }
                }
                if(a[start]>a[index])
                {
                    temp=a[start];
                    a[start]=a[index];
                    a[index]=temp;
                    reheapifydown(index,finish);
                }
            }
        }
                            
         template<class T>
        void array<T>::heapsort()
        {
            int i,temp;
            heapify();
            for(i=size;i>1;i--)
            {
                temp=a[1];
                a[1]=a[i];
                a[i]=temp;
                reheapifydown(1,i-1);
            }
        }
        
        template<class T>
        void array<T>::output()
        {
            int i;
            for(i=1;i<=size;i++)
            {
                cout<<a[i]<<"\t\t";
            }
            cout<<endl;
        }
        int main()
        {
            int n;
            cout<<"enter the size of array:"<<endl;
            cin>>n;
            array<int> a(n);
            a.inputarray();
            cout<<"\ninput array is:"<<endl;
            a.output();
            a.heapsort();
            cout<<"\nsorted array is:"<<endl;
            a.output();
        system("pause");
        return 0;
    }        
            
                            
                                    
                                
