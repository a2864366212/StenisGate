#include<iostream>
#include<map>
using namespace std;
map<int,bool>count_flag;
pair<map<int,bool>::iterator,bool>insertjudge;
int main()
{
	int n;
	cin>>n;
	int c;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>c;
		if(
		count_flag.find(-c)
		!=count_flag.end()		
		){ans++;}
		else{
			count_flag.insert(make_pair(c,true));
		}
	}
	cout<<ans;
	return 0;
} 
