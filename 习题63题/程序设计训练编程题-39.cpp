#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],ans[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ans[i]=0;
	}
	ans[0]=1;
	int max=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j]>=a[i])
			ans[i]++;
		}
		if(max<ans[i]) max=ans[i];
	}
	cout<<max;
	return 0;
}

