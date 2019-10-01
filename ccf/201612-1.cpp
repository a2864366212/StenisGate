#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
int c[1002];
int flag[1002]={0};
vector<int>ans;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int count=1+rand()%10;
		//scanf("%d",&count);
		flag[count]++;
	}
	for(int i=1;i<=1000;i++)
	{
		if(flag[i]!=0)
		{
			ans.push_back(i);
		}
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<' ';
	}
	int before=flag[ans[0]];
	for(int i=1;i<ans.size();i++)
	{
		if(before==n-flag[ans[i]]-before)
		{
			cout<<ans[i];
			return 0;
		}
		before+=flag[ans[i]];
	}
	cout<<-1;
	return 0;
} 
