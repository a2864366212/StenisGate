#include<iostream>
using namespace std;
int main()
{
	int group;
	cin>>group;
	for(int flag=0;flag<group;flag++)
	{
		int PersonNumber,Interval;
		cin>>PersonNumber>>Interval;
		int TheLastPerson=0;//N=1??
		for (int i=2; i<=PersonNumber; i++)
		{
			TheLastPerson=(TheLastPerson+Interval)%i;
		}
		cout<<TheLastPerson+1<<endl;//result??1		
	}
	return 0;
}

