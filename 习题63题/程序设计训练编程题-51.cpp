#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;
stringstream ss;
void tostring(int a,string&result)
{
	ss<<a;
	ss>>result;
	ss.clear();
	ss.str("");
}
int main()
{
	int m,n;
	cin>>m>>n;
	string tempi,tempn;
	tostring(n,tempn);
	for(int i=1;i<=m;i++)
	{
		tostring(i,tempi);
		if(tempi.find(tempn)!=string::npos||i%n==0)
		{
			cout<<i<<' ';
		}
	}
}
