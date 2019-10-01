#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	 int n;
	 cin>>n;
	 int a[50]={0},dp[50]={0};
	 for(int i=0;i<n;i++)
	 {
	 	cin>>a[i];
	 	dp[i]=1;
	 }
	 int mmax=1;
	 for(int i=1;i<n;i++)
	 {
	 	for(int j=0;j<i;j++)
	 	{
	 		if(a[j]>=a[i])
	 		{
	 			dp[i]=max(dp[i],dp[j]+1);
	 		}
	 	}
	 	if(mmax<dp[i]) mmax=dp[i];
	 }
	 cout<<mmax;
	return 0;
} 
