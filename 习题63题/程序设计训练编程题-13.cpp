#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int count[10]={0};
	char ch;
	string a;
	while(((ch=getchar())!=EOF)&&(ch!='\n'))
	{
		if(ch!=' ')
		{
			count[ch-'0']++;
		}
	}
	int c;
	for(int i=0;i<10;i++)
	{
		if(count[i]!=0&&i!=0)
		{
			c=i;
			break;
		}
	}
	cout<<c;
	for(int i=0;i<count[0];i++)
	{
		cout<<0;
	}	
	for(int i=1;i<count[c];i++)
	{
		cout<<c;
	}
	for(int i=c+1;i<10;i++)
	{
		if(count[i]!=0)
		{
			for(int j=0;j<count[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}

