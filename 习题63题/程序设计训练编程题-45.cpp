#include<iostream>
#include<stack> 
using namespace std;
stack<string>ans;
int main()
{
	int n;
	int flag=1;
	while(cin>>n)
	{
		if(n==0)break;
		cout<<"set-"<<flag<<endl;
		getchar();
		string str;
		for(int i=0;i<n;i++)
		{
			getline(cin,str);
			if(i%2==0) cout<<str<<endl;
			else ans.push(str);
			//<1,2> <3,4>     
		}
		while(!ans.empty())
		{
			cout<<ans.top()<<endl;
			ans.pop();
		} 
		flag++;
	}
	return 0;
} 
