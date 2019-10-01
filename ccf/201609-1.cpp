#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	
	int old;
	cin>>old;
	
	int max=-1;
	int new_;
	for(int i=1;i<n;i++)
	{
		cin>>new_;
		max= max<fabs(new_-old)?fabs(new_-old):max;
		old=new_;
	}
	cout<<max;
}
 
