#include<iostream>
#include<cstring>
#include <stdio.h>
using namespace std;
string replace(char ch)
{
	switch(ch)
	{
		case '0':return "(Zero)";break;
		case '1':return "(One)";break;
		case '2':return "(Two)";break;
		case '3':return "(Three)";break;
		case '4':return "(Four)";break;
		case '5':return "(Five)";break;
		case '6':return "(Six)";break;
		case '7':return "(Seven)";break;
		case '8':return "(Eight)";break;
		case '9':return "(Nine)";break;
	}
}
bool isCount(char ch)
{
	if('0'<=ch&&ch<='9')
	{
		return true;
	}else{
		return false;
	}
}
int main()
{
	string a;
	char ch;
	int flag[10]={0};
	while((ch=getchar())!= EOF)
	{
		if(isCount(ch))
		{
			flag[ch-'0']++;
			a+=replace(ch);
		}else{
			a+=ch;
		}
	}
	cout<<a<<endl;
	for(int i=0;i<=9;i++)
	{
		if(i==0)
		{
			cout<<flag[0];
		}else{
			cout<<" "<<flag[i];
		}
	}
}
