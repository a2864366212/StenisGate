#include<iostream>
#include<map>
using namespace std;
map<int,double>point_jidian;
void create(int b,int e,double jidian)
{
	for(int i=b;i<=e;i++)
	{
		point_jidian.insert(make_pair(i,jidian));
	}	
}
int main()
{
	create(0,59,0);
	create(60,63,1.0);
	create(64,67,1.5);
	create(68,71,2.0);
	create(72,74,2.3);
	create(75,77,2.7);
	create(78,81,3.0);
	create(82,84,3.3);
	create(85,89,3.7);
	create(90,100,4.0);
	int n;
	cin>>n;
	double sum=0,sumpoint=0;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sumpoint+=a[i];
	}
	int p;
	for(int i=0;i<n;i++)
	{
		cin>>p;
		sum+=point_jidian[p]*a[i];
	}	
	//cout<<sum/sumpoint;
	printf("%.2lf",sum/sumpoint);	
	return 0;
}
