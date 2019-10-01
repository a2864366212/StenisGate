#include<map>
#include<iostream>
#include<vector>
using namespace std;
map<int,int>c_num;
map<int,int>::iterator it;
pair<map<int,int>::iterator,bool>judge;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>c;
		judge=c_num.insert(make_pair(c,1));
		if(!judge.second)
		{
			c_num[c]++;
		}
	}
	int before=0;
	if(c_num.size()==1)
	{
		cout<<(*c_num.begin()).first;
		return 0;
	}
	for(it=c_num.begin();it!=c_num.end();it++)
	{
		if(it==c_num.begin())
		{
			before = (*it).second;
		}else{
			int num=(*it).second;
			if(before==n-num-before)
			{
				cout<<(*it).first;
				return 0;
			}
			else{
				before+=num;
			}
		}
	}
	cout<<-1;
	return 0;	
}
