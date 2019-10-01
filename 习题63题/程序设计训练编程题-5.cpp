#include<iostream>
#include<map>
using namespace std;
int main()
{
	int a,b;
	bool IsFirst=true;
	map<int,int>Count;
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
				b=b+Count[a];
				Count.erase(Count.find(a));
				Count.insert(make_pair(a,b));
			}
		}
	}
	for(mit=Count.rbegin();mit!=Count.rend();mit++)
	{
		if(mit==Count.rbegin())
			cout<<(*mit).first<<" "<<(*mit).second;
		else{
			cout<<endl;
			cout<<(*mit).first<<" "<<(*mit).second;	
		}
	}
	return 0;
}
