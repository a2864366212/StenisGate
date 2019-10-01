#include<iostream>
#include<stack>
#include<map>
#include<list>
using namespace std;
map<char,char>lr;
list<char>::iterator lit;
int main()
{
	int n;
	cin>>n;
	lr.insert(make_pair('<','>'));
	lr.insert(make_pair('[',']'));
	lr.insert(make_pair('{','}'));
	lr.insert(make_pair('(',')'));
	for(int ii=0;ii<n;ii++)
	{
		list<char>solution;
		//stack<char>solution;
		string str; 
		cin>>str;
		for(int i=0;i<str.size();i++)
		{
			if(i==0) solution.push_back(str[i]);
			else{
				lit=solution.end();
				lit--;
				if(lr[ *(lit) ]==str[i])
				{
					solution.erase(lit);
				}else{
					solution.push_back(str[i]);
				}
			}
		}
		if(solution.size()==0) cout<<"Yes"<<endl;
		else{
			cout<<"No"<<endl;
		}	
		
		solution.erase(solution.begin(),solution.end());
	}

	return 0;
}
