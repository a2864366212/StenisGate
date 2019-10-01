#include<iostream>
#include<cmath>
using namespace std;
void ans(int t1,int t2)
{
	if((t1+t2)%2==0){
		cout<<(t1+t2)/2;
		return;
	}
	double answer;
	answer=double(double(t1)+double(t2))/2;
	answer*=10;
	answer=round(answer);
	answer/=10;
	printf("%.1lf",answer);
}
int main()
{
	int t=20000000;
	cout<<t;
	/*int n;
	cin>>n;
	int min=0,max=0,temp1=0,temp2=0;
	for(int i=1;i<=n;i++)
	{
		int c;
		cin>>c;
		if(i==1) min=c;
		if(i==n) max=c;
		if(n%2==0)
		{
			if(i==n/2) temp1=c;
			if(i==n/2+1) temp2=c;
		}else{
			if(i==n/2+1)
			{
				temp1=c;
			}
		}
	}
	if(max<min)
	{
		int temp;
		temp=max;
		max=min;
		min=temp;
	}
	if(n%2==0){
		cout<<max<<' ';
		ans(temp1,temp2);
		cout<<' '<<min;
	}else{
		cout<<max<<' '<<temp1<<' '<<min;
	}*/
	return 0;
}
