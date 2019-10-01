#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int p[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int flag=p[i]-p[j];
			if(flag==-1||flag==1)
			{
				sum++;
			}
		}
	}
	cout<<sum;
	
	return 0;
} 
