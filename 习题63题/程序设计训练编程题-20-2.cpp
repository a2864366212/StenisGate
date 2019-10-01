#include<iostream>
#include<sstream>
using namespace std;
stringstream ss;
void change(char &ch)
{
	switch(ch)
	{
		case '4':ch='3';break;
		case '5':ch='4';break;
		case '6':ch='5';break;
		case '7':ch='6';break;
		case '9':ch='7';break;
		default:break;
	}
}
void strtollint(string &str,long long int&answer)
{
	ss<<str;
	ss>>oct>>answer;
	ss.clear();
	ss.str(""); 
}
int main()
{
	string str;
	int n;
	cin>>n;
	long long int ans;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		for(int i=0;i<str.size();i++)
		{
			change(str[i]);
		}
		//cout<<str<<endl;
		strtollint(str,ans);
		cout<<dec<<ans<<endl;
	}
	
	return 0;
} 
