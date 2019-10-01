#include<iostream>
#include<map>
#include<cstdlib>
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
		a= (rand() % (21));
		b= (rand() % (21));
		cout<<a<<" "<<b<<endl;
		
		if(a==b&&b==0)
		{
			cout<<"************************"<<endl;
			if(IsFirst)
			{
				IsFirst=false;	
			}
			else
			{
				break;
			}
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
		if(mit==Count.rbegin())
			cout<<(*mit).first<<" "<<(*mit).second;
		else{
			cout<<endl;
			cout<<(*mit).first<<" "<<(*mit).second;	
		}
	}
	return 0;
}
