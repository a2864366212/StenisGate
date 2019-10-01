#include<iostream>
using namespace std;
int main()
{
	int tb[105],te[105];
	int n,p1,p2,p3,t1,t2;
	cin>>n>>p1>>p2>>p3>>t1>>t2;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>tb[i]>>te[i];
		sum+=te[i]-tb[i];
	}
	int w1=p1*sum,w2=0,w3=0;
	
	for(int i=0;i+1<n;i++)
	{
		if((tb[i+1]-te[i])<=t1)
		{
			w1+=(tb[i+1]-te[i])*p1;
			continue;
		}else{
			if((tb[i+1]-te[i]-t1) <=t2 )
			{
				w1+=t1*p1;
				w2+= (tb[i+1]-te[i]-t1) *p2;
			}else{
				w1+=t1*p1;
				w2+=t2*p2;
				w3+=(tb[i+1]-te[i]-t1-t2)*p3;
			}
		}
	}
	cout<<w1+w2+w3;
	return 0;
}
