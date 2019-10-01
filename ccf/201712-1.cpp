#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int id[1005];
int flag[1005]={0};
int k;
bool isdefeat(int count)
{
	if(count%k==0||count%10==k)
	{
		return true;
	}else return false;
}
int main()
{
	int n;
	cin>>n>>k;
	
	for(int i=0;i<n;i++)
	{
		id[i]=i+1;
	}
	int count=0;
	int num=0;
	for(int i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			count++;
			if(isdefeat(count))
			{
				flag[i]=1;/*defeat*/
				num++;
				if(num==n-1)
				{
					break;
				}
			}
		}
		
		if(i==n-1) i=-1;
	}
	
	for(int i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			cout<<id[i];
		}
	}
	return 0;
}
