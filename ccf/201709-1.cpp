#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	n/=10;
	int ans=0;
	while(1)
	{
		if(n>=5)
		{
			n-=5;
			ans+= 7;
		}else break;
	}
	while(1)
	{
		if(n>=3)
		{
			n-=3;
			ans+= 4;
		}else break;
	}
	ans+=n;
	cout<<ans;
	return 0;
} 
