#include<iostream>
#include<cstring>
#include<map>
using namespace std;
bool chengn(string&count,int n,int *a)
{
	for(int i=0;i<count.size();i++)
	{
		a[i]=count[i]-'0';
		a[i]*=n;
	}
	for(int i=count.size()-1;i>=1;i--)
	{
		a[i-1]+=a[i]/10;
		a[i]%=10;	
	}
	if(a[0]>10){
		return 1;/*需要进位*/
	}else return 0;
}
int main()
{
	string count;
	cin>>count;
	map<string,int>change_flag;
	map<string,int>::iterator it;
	pair<map<string,int>::iterator,bool>InsertJudge;
	string temp=count;
	for(int step=1;step<=count.size();step++)
	{
		temp.push_back(temp[0]);
		temp.erase(0,1);
		change_flag.insert(make_pair(temp,1));
	}
	int maxn=count.size();
	for(int n=1;n<=maxn;n++)
	{
		int a[count.size()];
		string temp;
		if(!chengn(count,n,a))
		{
			for(int i=0;i<count.size();i++)
			{
				temp+= char('0'+a[i]);
			}	
			//cout<<temp<<endl;
		}	
		if(change_flag.find(temp)==change_flag.end())
		{
			cout<<"No";
			return 0; 
		}
	}
	cout<<"Yes";
	
	return 0;
} 
