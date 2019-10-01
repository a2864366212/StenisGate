#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
struct count
{
	int c=-1;
	int time=0;
};
bool compare(struct count a,struct count b)
{
	if(a.time!=b.time)
	return a.time>b.time;
	else{
		return a.c<b.c;
	}
}
int main()
{
	int n;
	cin>>n;
	int temp;
	struct count num[n];
	int max=-1;
	srand(NULL);
	for(int i=0;i<n;i++)
	{
		
		temp=i+1;
		if(max<temp) max=temp;
		num[temp].c=temp;
		num[temp].time++;
	}
	sort(num,num+max+1,compare);
	for(int i=0;i<n;i++)
	{
		if(num[i].time==0)break;
		cout<<num[i].c<<' '<<num[i].time<<endl;
	}
	return 0;
}
