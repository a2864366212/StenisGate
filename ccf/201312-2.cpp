#include<iostream>
#include<cstring>
using namespace  std;
int main()
{
	string str;
	cin>>str;
	string ans;
	for(int i=0;i<str.size()-1;i++)
	{
		if(str[i]!='-')
		{
			ans+=str[i];
		}
	}
	
	int check=0;
	for(int i=0;i<ans.size();i++)
	{
		check+=( ans[i]-'0' )*(i+1);
	}
	check%=11;
	
	char ch=str[str.size()-1];
	
	if(check==10)
	{
		if(ch=='X') cout<<"Right";
		else 
		{
			str[str.size()-1]='X';
			cout<<str;
		}
	}else{
		if(ch==check+'0')
		{
			cout<<"Right";
		}else{
			str[str.size()-1]=check+'0';
			cout<<str;
		}
	}
	return 0;
}
