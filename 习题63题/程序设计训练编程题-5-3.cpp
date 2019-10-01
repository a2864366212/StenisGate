#include<iostream>
#include<map>
using namespace std;
int main()
{
	int a,b;
	bool IsFirst=true;
	map<int,int>Count,result;
	map<int,int>::reverse_iterator mit;
	pair<map<int,int>::iterator,bool>InsertJudge;
	for(int i=0;;i++)
	{
		cin>>a>>b;
		if(a==b&&b==0)
		{
			if(IsFirst)
				IsFirst=false;	
			else
				break;
		}
		else{
			InsertJudge=Count.insert(make_pair(a,b));
			if(!InsertJudge.second)
			{
				Count[a]+=b;
			}
		}
	}
	for(mit=Count.rbegin();mit!=Count.rend();mit++)
	{		
		if(mit->second!=0)
		{
			result.insert(make_pair(mit->first,mit->second));
		}
	}
	for(mit=result.rbegin();mit!=result.rend();mit++)
	{		
		cout<<mit->first<<" "<<mit->second<<endl;
	}	
	return 0;
}
