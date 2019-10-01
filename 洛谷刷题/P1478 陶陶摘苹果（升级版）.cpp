#include<iostream>
using namespace std;
int h[5500],cost[5500],path[5500];
int DP[5500][1100]={0};
int dp(int index,const int n,const int personheight,int power,int DP[5500][1100])
{
	if(power<0) return -9999999;
	if(power==0||index==n) return 0;
	
	if(h[index]<=personheight){
		if(DP[index+1][power-cost[index]]==0){
			DP[index+1][power-cost[index]]=dp(index+1,n,personheight,power-cost[index],DP);
		}
		if(DP[index+1][power]==0){
			DP[index+1][power]=dp(index+1,n,personheight,power,DP);
		}
		return max(1+DP[index+1][power-cost[index]],DP[index+1][power]);
	}
	else{
			if(DP[index+1][power]==0){
			DP[index+1][power]=dp(index+1,n,personheight,power,DP);
		}
			return DP[index+1][power];
	} 	
}
int main()
{
	int n,power,a,b;
	cin>>n>>power>>a>>b;

	for(int i=0;i<n;i++){
		cin>>h[i]>>cost[i];
	}
	cout<<dp(0,n,a+b,power,DP);
	return 0;
} 
