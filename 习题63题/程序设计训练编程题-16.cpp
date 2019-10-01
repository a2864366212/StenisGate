#include<iostream>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	int NonCount=0;
	for(int i=0;i<b.size();i++)
	{
		if(a.find(b[i])==string::npos)
		{
			NonCount++;
		}else{
			a.erase(a.find(b[i]),1);
		}
	}
	if(NonCount==0)
	{
		cout<<"Yes "
			<<a.size();
	}else{
		cout<<"No "
			<<NonCount;
	}
	return 0;
} 
