#include<iostream>
#include<cstring>
using namespace std;
string in;
// +-*/ 1 2 3 4
int ans(int begin,int end,int fromflag)
{
	bool canresult=true;
	for(int i=begin+1;i<=end;i++)
	{
		if(in[i]=='+')
		{
			canresult=false;
			return ans(begin,i-1,fromflag)+ans(i,end,1);
		}else{
			if(in[i]=='-')
			{
				canresult=false;
				return ans(begin,i-1,fromflag)+ans(i,end,2);
			}
		}
	}
	
	if(canresult)
	{
		int sum=in[begin+1]-'0';
		if(fromflag==2)
		{
			sum=-sum;
		}
		for(int i=begin+2;i<=end;i+=2)
		{
			if(in[i]=='*')
			{
				sum*= int(in[i+1]-'0');
			}
			if(in[i]=='/')
			{
				sum/= int(in[i+1]-'0');
			}
		}
		return sum;
	}

}
int main()
{
	cin>>in;
	in.insert(0,"+");
	cout<<  ans(0,in.size()-1,1);
	return 0;
} 
