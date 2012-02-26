#include <iostream>
#define N 4
#define W 10
using namespace std;
int main()
{
	int weight[W+1][N+1]={0};	
	int items[N][2];
	for(int i =0;i < N;i++)
	{
		//cout<<"Weight: ";
		cin>>items[i][0];
		//cout<<"Value: ";
		cin>>items[i][1];
	}
	
	for(int i = 1;i <= N;i++)
	{
		for(int j = 1; j <= W; j++)
		{
			if(j >= items[i-1][0])
			{
				int temp_max = weight[j-items[i-1][0]][i-1] + items[i-1][1];
				if(temp_max > weight[j][i-1])
					weight[j][i] = temp_max;
				else
					weight[j][i] = weight[j][i-1];
			}
			else
				weight[j][i] = weight[j][i-1];
		}
	}
	cout<<"The maximum value possible is "<<weight[W][N]<<endl;

	system("pause");
	return 0;
}
/*
Input
6
30
3
14
4
16
2
9
*/

