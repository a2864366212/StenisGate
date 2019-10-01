#include<iostream>
#include<vector>
using namespace std;
vector<int>ans;
int flag[10001];
int main()
{
	for(int i=0;i<10001;i++)
	flag[i]=0;
	
	int n;
	cin>>n;
	int *p=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		flag[p[i]]++;
	}
	
	int max=0;
	for(int i=0;i<10001;i++)
	{
	//	cout<<i<<' '<<flag[i]<<endl;
		if(flag[i]>max)
		{
			max=flag[i];
		}
	}
	//cout<<max;
	for(int i=0;i<10001;i++)
	{
		if(flag[i]==max)
		{
			ans.push_back(i);
		}
	}	
	//9+3+4*3
	int min=999999;
	for(int i=0;i<ans.size();i++)
	{
		//cout<<ans[i]<<endl;
		if(min>ans[i])
		{
			min=ans[i];
		}
	}
	
	cout<<min;
	return 0;
} 
