#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
set<int>result;
set<int>::iterator it;

int main()
{
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a;i++)
	{
		int j;
		cin>>j;
		result.insert(j);
	}
	int num=0;
	if(b>result.size())
	{
		num=result.size();
	}else num=b;
	int n=0; 
	for(it=result.begin();it!=result.end();it++)
	{
		if(n==0)
		cout<<(*it);
		else{
			cout<<' '<<(*it);
		}
		n++;
		if(n==num) break;
	} 
} 
