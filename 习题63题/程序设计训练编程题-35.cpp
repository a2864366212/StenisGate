#include<iostream>
#include<list>
#include<map>
#include<cstring>
using namespace std;
struct space
{
	int val;/*占用使用负数代表 空闲正数表示*/
	int id;
};
list<space>s;
list<space>::iterator lit,latter;
map<int,int>id_state;/*-1 占用 */
map<int,int>::iterator mit;
void hebing()
{
	list<struct space>::iterator temp;
	for(lit=s.begin();lit!=s.end();lit++)
	{
		if(lit->val>0)
		{
			temp=lit;
			temp++;
			if(temp==s.end()) return;
			while(1)
			{
				if(temp==s.end()) return;
				if(temp->val>0)
				{
					lit->val+=temp->val;
					temp=s.erase(temp);
				}else break;				
			}
		}
	}
}
void test()
{
	cout<<endl;
	for(lit =s.begin();lit!=s.end();lit++)
	{
		cout<<"id "<<lit->id<<" val "<<lit->val<<endl;
	}	
}
int main()
{
	string in="in",out="out";
	int n,m,k;
	cin>>n>>m>>k;
	
	struct space t;
	t.id=-1;
	t.val=n*n;
	s.push_back(t);
	
	string str;
	int id,num;
	for(int i=0;i<k;i++)
	{
		cin>>str;
		if(str==in)
		{	cin>>id>>num;
			if(id_state.find(id)!=id_state.end())
			{
				cout<<"no"<<endl;
				continue; 
			}
			else{
				bool allocfail=true;
				for(lit=s.begin();lit!=s.end();lit++)
				{
					if(lit->val==num)
					{
						lit->val=-num;
						lit->id=id;
						id_state.insert(make_pair(id,-1));
						cout<<"yes"<<endl;
						allocfail=false;
						break;
					}else{
						if(lit->val>num)
						{
							struct space temp;
							temp.val=lit->val-num;
							temp.id=-1;
							latter=lit;
							latter++;
							s.insert(latter,temp);
							
							lit->val=-num;
							lit->id=id;
							id_state.insert(make_pair(id,-1));
							cout<<"yes"<<endl;
							allocfail=false;
							break;
						}
					}
				}
				if(allocfail)
				{
					cout<<"no"<<endl;
				}	
			}
				
		}
		if(str==out)
		{
			int id;
			cin>>id;
			if(id_state.find(id)!=id_state.end())
			{
				id_state.erase( id_state.find(id) );
				for(lit=s.begin();lit!=s.end();lit++)
				{
					if(lit->id==id)
					{
						if(lit->val<0)
						{
							lit->val=-lit->val;
						}
						break;
					}
				}
				cout<<"yes"<<endl;
			}else{
				cout<<"no"<<endl;
			}
		}
		//test();	
		hebing();
	} 
	/*int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		sltruct space temp;
		cin>>temp.val;
		temp.id=i;
		s.push_back(temp);
	}
	hebing();
	for(lit =s.begin();lit!=s.end();lit++)
	{
		cout<<lit->val<<endl;
	}*/
	return 0;
}  
