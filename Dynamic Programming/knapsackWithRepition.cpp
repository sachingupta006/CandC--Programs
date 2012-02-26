#include <iostream>
#define N 4
#define W 10
using namespace std;
int main()
{
	int weight[W+1]={0};	
	int items[N][2];
	for(int i =0;i < N;i++)
	{
		cout<<"Weight: ";
		cin>>items[i][0];
		cout<<"Value: ";
		cin>>items[i][1];
	}
	
	for(int i=1;i <= W;i++)
	{
		int max = -1;
		for(int j = 0;j < N; j++)
		{
			if(i-items[j][0] >= 0)
			{
				int temp_max = weight[i-items[j][0]] + items[j][1];
				if(temp_max > max)
				{
					weight[i] = temp_max;
					max = temp_max;
                }
			}
		}
	}
	int i = W;
	while(true)
	{
        if(weight[i] != 0)
			break;
		else
			i++;
    }
	cout<<"The maximum value possible is "<<weight[i]<<" at a weight of "<<i<<endl;

	system("pause");
	return 0;
}
