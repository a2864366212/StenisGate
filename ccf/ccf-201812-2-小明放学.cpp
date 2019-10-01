#include<iostr+eam>
using namespace std;
int judge(int sum,int k,int t,int T,int *a)
{
	int yu=sum%T;
	int start;/*0 1 2 3 4*/
	if(k==1) start= a[0]-t;
	if(k==3) start= a[0]+a[1]-t;
	if(k==2) start= a[0]+a[1]+a[2]-t;
	
	start+=yu;
	 
	yu=start%T;
	

	if(yu<=a[0]) return a[0]-yu;
	else 
	{
		if(yu<=a[1]+a[0]) return 0;
		else return a[0]+a[2]-yu+a[0]+a[1];
	}
}
int main()
{
	int ryg[3],n,k,t,T=0;
	
	cin>>ryg[0]>>ryg[2]>>ryg[1]>>n;
	T=ryg[0]+ryg[1]+ryg[2];
	int sum=0;
	for(int i=0;i<=n-1;i++)
	{
		cin>>k>>t;
		if(k==0)
		{
			sum+=t;
		} 
		else sum+=judge(sum,k,t,T,ryg);
		
	}
	cout<<sum;
	//sum=10;
	//cout<<judge(sum,1,5,T,ryg);
	return 0;
} 
