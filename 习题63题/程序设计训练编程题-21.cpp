#include<iostream>
#include<stack>
#include<map>
using namespace std;
map<char,char>lr;

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
		stack<char>solution;
		string str; 
		cin>>str;
		for(int i=0;i<str.size();i++)
		{
			if(i==0) solution.push(str[i]);
			else{
				if(lr[solution.top()]==str[i])
				{
					solution.pop();
				}else{
					solution.push(str[i]);
				}
			}
		}
		if(solution.size()==0) cout<<"Yes"<<endl;
		else{
			cout<<"No"<<endl;
		}	
	}

	return 0;
}
