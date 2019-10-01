#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int flag[10]={0};
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		flag[str[i]-'0']++;
	}
	for(int i=0;i<10;i++)
	{
		if(flag[i]!=0)
		{
			cout<<i<<':'<<flag[i]<<endl;
		}
	}
	return 0;
}
