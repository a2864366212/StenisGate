#include<iostream>
#include<list>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	
	list<int>stu;
	list<int>::iterator it,it2,temp;
	for(int i=1;i<=n;i++)
	{
		stu.push_back(i);
	}
	stu.push_back(9999);
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		int id,pos;
		cin>>id>>pos;
		int index=1;
		for(it=stu.begin();it!=stu.end();)
		{
			if((*it)==id)
			{	
				break;
			}
			it++; 
			index++;
		}
				it=stu.erase(it);	
				//cout<<(*it)<<"*****"<<endl;	
				for(int j=1;j<=abs(pos);j++)
				{
					if(pos<0)
					it--;
					else
					it++;
				}	
				stu.insert(it,id);
				
				

	}
	it=stu.end();
	it--;
	stu.erase(it);
	for(it=stu.begin();it!=stu.end();it++)
	{
		cout<<(*it)<<' ';
	}
	
	return 0;
} 
