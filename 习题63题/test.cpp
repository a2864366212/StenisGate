#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{	
	stack<string>sta;
	string a="";
	char b=cin.get();
	while(b!=EOF)
	{
		if(b!='\n')
		{
			if(b!=' ')
			{
				a+=b;
			}
			else
			{
				//cout<<a<<' ';
				sta.push(a);
				a="";
			}
		}
		else
		{
			//cout<<a<<' ';
			cout<<a;
			a="";
			while(sta.size()) 
			{
				cout<<' '<<sta.top();
				sta.pop();
			}
			cout<<'\n';
		}
		b=cin.get();
	}
	return 0;
}

