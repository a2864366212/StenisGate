#include<iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int now=k;
	int c;
	
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>c;
		now-=c;
		if(now<=0)
		{
			ans++;
			now=k;
		}
	}
	if(now<k)
	{
		ans++;
	}
	cout<<ans;
	return 0;
} 
