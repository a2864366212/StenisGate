#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int num[n];
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	sort(num,num+n);
	cout<<num[n-1]<<' ';
	
	if(n%2 == 0)
	{
		double sum;
		sum = (num[n/2-1]+num[n/2])/2.0;
		if((num[n/2-1]+num[n/2])%2 == 0)
		{
			cout<<sum<<' ';
			//printf("%.0lf ",sum);
			//cout<<(num[n/2-1]+num[n/2])/2<<' ';
		}
		else
		{
			sum*=10;
			sum=round(sum);
			sum/=10;
			cout<<sum<<' ';
		}
	}
	else
	{
		cout<<num[(n+1)/2-1]<<' ';
	}
	cout<<num[0];
	return 0;
 }
