#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
struct window
{
	int x1;
	int y1;
	int x2;
	int y2;
	int id;
};
bool include(int x,int y,struct window&temp)
{
	if(temp.x1<=x&&x<=temp.x2)
	{
		if(temp.y1<=y&&y<=temp.y2)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int n,m;
	cin>>n>>m;
	list<struct window>ans;
	list<struct window>::iterator it;
	
	for(int i=0;i<n;i++)
	{
		struct window temp;
		cin>>temp.x1>>temp.y1>>temp.x2>>temp.y2; 
		temp.id=i+1;
		ans.push_back(temp);
	}
	reverse(ans.begin(),ans.end());
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		bool isignored=true;
		for(it=ans.begin();it!=ans.end();it++)
		{
			if(include(x,y,(*it) ) )
			{
				struct window temp;
				temp=(*it);
				ans.erase(it);
				ans.insert(ans.begin(),temp);
				cout<<temp.id<<endl;
				isignored=false;
				break;
			}
		}
		/*for(it=ans.begin();it!=ans.end();it++)
		{
			struct window c= *it;
			cout<<c.id<<endl
				<<c.x1<<" "<<c.y1<<" "<<c.x2<<" "<<c.y2<<endl;
		}*/
	//	cout<<endl<<endl;
		if(isignored)
		{
			cout<<"IGNORED"<<endl; 
		}		
	}

	return 0;
} 
