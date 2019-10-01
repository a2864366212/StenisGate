#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
map<string,int>tele_time;
pair<map<string,int>,bool>InsertJudge;
map<string,int>::iterator mit; 
vector<string>ans;
void change(char&ch)
{
	if(!('0'<=ch&&ch<='9'))
	{
		if((ch-'A')/3<=4)
		{
			ch=(ch-'A')/3+2+'0';
		}else{
			if(ch=='P'||ch=='R'||ch=='S') ch=7+'0';
			else{
				if(ch=='T'||ch=='U'||ch=='V') ch=8+'0';
				else{
					if(ch=='W'||ch=='X'||ch=='Y') ch=9+'0';
				}
			}
		}
	}
}
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
				change((*it));
				it++;
			}
		}
		
		if(tele_time.find(str)!=tele_time.end())
		{
			tele_time[str]++;
		}else tele_time.insert(make_pair(str,1));
	}
		for(mit=tele_time.begin();mit!=tele_time.end();mit++)
		{
			int t=mit->second;
			if(t>1)
			{
				cout<<(mit->first).substr(0,3)<<'-'<<(mit->first).substr(3,4)<<' '<<t<<endl;
			}
			//cout<<mit->first<<' '<<mit->second<<endl;
		}
	return 0;
}
