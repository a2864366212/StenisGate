#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
map<string,int>tele_time;
pair<map<string,int>,bool>InsertJudge;
map<string,int>::iterator mit; 
vector<string>ans;
int main()
{
	string str;
	int n;
	cin>>n;
	getchar();
	string::iterator it;
	for(int i=0;i<n;i++)
	{
		getline(cin,str);
		for(it=str.begin();it!=str.end();)
		{
			if((*it)=='-')
			{
				it=str.erase(it);
			}else{
				it++;
			}
		}
		InsertJudge=tele_time.insert(make_pair(str,1));
		if(InsertJudge.second==false)
		{
			tele_time[str]++;
		}
		for(mit=tele_time.begin();mit!=tele_time.end();mit++)
		{
			int t=mit->second;
			if(t>1)
			{
				cout<<str.substr(0,3)<<'-'<<str.substr(3,4)<<endl;
			}
		}
	}
	
	return 0;
}
