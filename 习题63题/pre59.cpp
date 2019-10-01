#include<iostream>
#include<map>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
map<string,int>dic;
vector<string>ans;
vector<string>::iterator it;
bool cmp(string a,string b)
{
	return dic[a]<dic[b];
}
int main()
{
	string str;
	int order=0;
	while(1)
	{
		cin>>str;
		if(str=="#")
		{
			break;
		}
		dic.insert(make_pair(str,order));
		order++;
	}
	while(cin>>str)
	{
		int blank=0;
		if(str=="#")  break;
		
		if(dic.find(str)!=dic.end())
		{
			cout<<str<<" is correct\n";
			continue;
		}
		else{
			cout<<str<<": ";
		}
		string sub;
		for(int i=0;i<str.size();i++)
		{
			sub=str;
			sub.erase(i,1);
			if(dic.find(sub)!=dic.end())
			{
				ans.push_back(sub);
			}
			//cout<<sub<<endl;
		}
		char ch;
		for(ch='a';ch<='z';ch++)
		{
			for(int i=0;i<=str.size();i++)
			{
				sub=str;
				string t;t+=ch;
				sub.insert(i,t);
				if(dic.find(sub)!=dic.end())
				{
					ans.push_back(sub);
				}
				//cout<<sub<<endl;
			}
		}
		for(ch='a';ch<='z';ch++)
		{
			for(int i=0;i<str.size();i++)
			{
				sub=str;
				sub[i]=ch;
				if(dic.find(sub)!=dic.end())
				{
					ans.push_back(sub);
				}
				//cout<<sub<<endl;
			}
		}
		sort(ans.begin(),ans.end(),cmp);
		for(it=ans.begin();it!=ans.end();it++)
		{
			if(it==ans.begin()) cout<<(*it);
			else cout<<" "<<(*it);
		}
		cout<<endl;
		ans.erase(ans.begin(),ans.end());
	}
	return 0;
}
