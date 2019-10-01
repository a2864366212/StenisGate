/*　
	1） 个人所得税起征点为3500元，若S不超过3500，则不交税，
	3500元以上的部分才计算个人所得税，令A=S-3500元；
　　2） A中不超过1500元的部分，税率3%；
　　3） A中超过1500元未超过4500元的部分，税率10%；
　　4） A中超过4500元未超过9000元的部分，税率20%；
　　5） A中超过9000元未超过35000元的部分，税率25%；
　　6） A中超过35000元未超过55000元的部分，税率30%；
　　7） A中超过55000元未超过80000元的部分，税率35%；
　　8） A中超过80000元的部分，税率45%；
*/
#include<iostream>
#define exps 0.000000001
using namespace std;
int main()
{
	double sum[9]={0,3500,0,0,0,0,0,0,0};
	double m[9]={0,3500,0,0 ,0,0,0,0,0};
	double rate[7]={0.03,0.1,0.2,0.25,0.3,0.35,0.45};
	double delta[7]={1500,3000,4500,26000,20000,25000,10000000};
//	cout<<0<<' '<<3500<<' ';
	for(int i=0;i<7;i++)
	{
		m[i+2]=delta[i]*(1-rate[i])+m[i+1];
		sum[i+2]=delta[i]+sum[i+1];
//		cout<<sum[i+2]<<' ';
	}
//	cout<<endl;
	int t;
	cin>>t;
//	for(int i=0;i<9;i++) cout<<m[i]<<' ';
//	cout<<endl;
	
	for(int i=0;i<8;i++)
	{
		//m[i] m[i+1]
		if(m[i]+exps<t&&t<=m[i+1]+exps)
		{
			//i i+1
			//cout<<i<<' '<<i+1<<endl;
			 double answer= (t-m[i+1])/(1-rate[i-1]) +sum[i+1];
			 long long int ans=(answer); 
			 cout<<ans;
			 return 0;
		}
	}
	return 0;
} 
