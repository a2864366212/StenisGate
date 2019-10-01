#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<string,int>name_time;
map<string,int>::iterator it;
pair<map<string,int>::iterator,bool>InsertJudge;
int main()
{
	int n;
	
	while(cin>>n) 
	{
		if(n==0)break;
		char str[100];
		for(int i=1;i<=2*n-1;i++)
		{
			scanf("%s",str);
			string temp(str);
			InsertJudge=name_time.insert(make_pair(temp,1));
			if(InsertJudge.second==false)
			{
				name_time[temp]++;
			}
		}
		for(it=name_time.begin();it!=name_time.end();it++)
		{
			if((it->second)%2!=0 )
			{
				cout<<it->first<<endl;
				break;	
			}
		}	
		name_time.erase(name_time.begin(),name_time.end());	
	}

	return 0;
}
