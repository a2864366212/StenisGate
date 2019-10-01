#include<iostream>
using namespace std;
void ans(int& sum,int n)
{
	sum=0;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0){
			if(i!=n/i){
			  	sum+=i+n/i;
			}
			else sum+=i;
			//cout<<i<<n/i<<endl;
		}
	
	}
	sum-=n;		
}
int main()
{
	int a,b;
	while(cin>>a>>b){
		int sum=0,sum2=0;	
		ans(sum,a);
		//cout<<sum<<endl;
		ans(sum2,b);
		//cout<<sum2<<endl;
		if(sum==b&&sum2==a)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}
