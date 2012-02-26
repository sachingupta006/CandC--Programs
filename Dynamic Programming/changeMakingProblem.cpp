#include <iostream>
#define N 4
#define C 17
using namespace std;
int main()
{
	int coins[N]={1,2,5,10};
	int amount[C+1]={0};
	
	for(int amt = 1; amt <= C ;amt++)
	{
		amount[amt] = INT_MAX;
		int temp = INT_MAX;
		for(int c = 0; c < N;c++)
		{
			if(coins[c] <= amt)
			{
				int temp_amt = amount[amt-coins[c]] + 1;
				if(temp_amt < temp)
				{
					temp = temp_amt;
					amount[amt] = temp;
				}
			}
		}
	}
	cout<<"The minimum number of coins to be used for amount "<<C<<" are "<<amount[C]<<endl;

	system("pause");
	return 0;
}
