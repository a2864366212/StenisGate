#include<iostream>
#include<map>
#include<cstring>
#include<vector>
using namespace std;
vector<string>test;
map<string,string>dic;
map<string,string>::iterator it;
int main()
{
	string str,sub1,sub2;
	while(1)
	{
		getline(cin,str);
		//getchar();
		//test.push_back(str);
		if(str.find("END")!=string::npos) break;
		sub1=str.substr(0,str.find(']')+1 );
		sub2=str.substr(str.find(']')+2,str.size()-str.find(']')-2);
		
		dic.insert(make_pair(sub1,sub2));
		dic.insert(make_pair(sub2,sub1));
	}
	/*for(it=dic.begin();it!=dic.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}*/
	int n;
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	{
		getline(cin,str);
		
		if(dic.find(str)!=dic.end())
		cout<<(dic.find(str)->second)<<endl;
		else cout<<"what?"<<endl;	
	}
	return 0;
}
