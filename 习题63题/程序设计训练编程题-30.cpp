#include<iostream>
# define noflag 99999999
using namespace std;
int dp(int money,int *paper,int index,int k)
{
	if(index>=k||money<0) return noflag;
	if(money==0) return 0;
	return min(1+dp(money-paper[index],paper,index,k)
	,
	dp(money,paper,index+1,k));
}
int main()
{
	while(1)
	{
		int money;
		cin>>money;
		if(money==0) break;
		
		int k;
		cin>>k;
		int paper[k];
		for(int i=0;i<k;i++) cin>>paper[i];
		
		int result=dp(money,paper,0,k);
		if(result!=noflag) cout<<result<<endl;
		else cout<<"Impossible"<<endl;
	}

	return 0;
}
