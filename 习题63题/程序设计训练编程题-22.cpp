#include<iostream>
#include<cstring>
#include<map>
using namespace std;
char count[16]={'0','1','2','3','4','5','6','7','8','9',
				'a','b','c','d','e','f'};
int answer(string &str,int jinzhi)
{
	int beforemod=0;
	str+='0';
	for(int i=0;i<str.size();i++)
	{/*letter to count letter-'a'+10*/
		if(str[i]<='9')
		beforemod=(beforemod*jinzhi + str[i]-'0')%(jinzhi-1);
		else
		beforemod=(beforemod*jinzhi + (str[i]-'a'+10) )%(jinzhi-1);		
	}
	int xiaojianma;
	if(beforemod!=0)
	{
		 xiaojianma= jinzhi-1-beforemod;
	}
	return xiaojianma;
}
int main()
{
	int group;
	cin>>group;
	for(int g=0;g<group;g++)
	{
		string str;
		int jinzhi;
		
		cin>>jinzhi>>str;
		
		int ans=answer(str,jinzhi);
		if(ans<=9)
		cout<<ans<<endl;
		else
		cout<<char(ans-10+'a')<<endl;
	}
	return 0; 
}
