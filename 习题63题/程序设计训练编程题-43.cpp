#include<iostream>
#define MAXLENGTH 20 
using namespace std;
int a[MAXLENGTH][MAXLENGTH]={0};
void ans(int beginr,int beginc,int flag,int circle,int timer,const int n)
{
	int endrow,endcol;
	if(flag==1){
		for(int i=beginr;i<=beginr+circle-1;i++){
			a[i][beginc]=timer;
			//cout<<i<<" "<<beginc<<' '<<timer<<endl;
			timer++;
		}
		endrow=beginr+circle-1;
		for(int i=beginc-1;i>=beginc-(circle-1);i--){
			a[endrow][i]=timer;
			//cout<<endrow<<" "<<i<<' '<<timer<<endl;
			timer++;
		}
		endcol=beginc-(circle-1);
	}else{
		for(int i=beginr;i>=beginr-(circle-1);i--)
		{
			a[i][beginc]=timer;
			//cout<<i<<' '<<beginc<<' '<<timer<<endl;
			timer++;
		}
		endrow=beginr-(circle-1);
		for(int i=beginc+1;i<=beginc+(circle-1);i++)
		{
			a[endrow][i]=timer;
			//cout<<endrow<<' '<<i<<' '<<timer<<endl;
			timer++;
		}
		endcol=beginc+(circle-1);
	}
	if(circle==n) return;
	if(flag==1) ans(endrow,endcol-1,-flag,circle+1,timer,n);
	else ans(endrow,endcol+1,-flag,circle+1,timer,n);
}	
int main()
{
	int n;
	cin>>n;
	int beginr,beginc;
	if(n%2==0)
	{
		beginc=beginr=n/2-1;
	}else{
		beginc=beginr=n/2;
	}
	a[beginr][beginc]=1;
	if(n==1)
	{
		cout<<1;
		return 0;
	} 
	ans(beginr,beginc+1,1,2,2,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
