#include<iostream>
using namespace std;
bool isanspoint(int &a,int &b,int &c)
{
	if( (a>b&&b<c)|| (a<b&&b>c) )
	{
		return true;
	}else{
		return false;
	}
}
int main()
{
	int a,b,c;
	int n;
	cin>>n;
	cin>>a>>b;
	int ans=0;
	for(int i=2;i<n;i++)
	{
		cin>>c;
		if(isanspoint(a,b,c))
		{
			ans++;
		}
		a=b;
		b=c;
	}
	cout<<ans;
	return 0;
}
