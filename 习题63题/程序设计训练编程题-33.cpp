#include<iostream>
#include<cstring>
#include<map> 
#include<list>
using namespace std;
struct space
{
	int val;/*小于0 被占用 大于零 有空间*/ 
	int id;
	bool operator<(space b)
	{
		return this->id<b.id;
	}
};
list<struct space>s;
list<struct space>::iterator before,now,latter,lit,temp;
map<int,bool>id_erase;
map<int,bool>::iterator mit;
void hebing()
{
	for(lit=s.begin();lit!=s.end();lit++)
	{
		if(lit->val>0)
		{
			latter=lit;
			latter++;
			if(latter==s.end())return;
			while(1)
			{
				if(latter==s.end())return;
				if(latter->val>0)
				{
					lit->val+=latter->val;
					latter=s.erase(latter);
				}else{
					break;
				}				
			}
		}
	}	
}
void test()
{
		cout<<"6666"<<endl;;
		for(lit=s.begin();lit!=s.end();lit++)
		{
			cout<<lit->val<<endl;
		}	
}
int main()
{
	int n,m;
	cin>>n>>m;
	getchar();
	string alloc="alloc",erase="erase",defragment="defragment";
	string str; 
	int endspace=m;
	int x=1;
	struct space te;
	te.id=-1;
	te.val=endspace;
	s.insert(s.begin(),te);
	for(int i=0;i<n;i++)
	{
		cin>>str;
		if(str==alloc)
		{
			bool allocFail=true;
			int size;
			cin>>size;
			struct space temp;
			for(before=lit=s.begin();lit!=s.end();lit++)
			{
				if(lit->val==size)
				{
					lit->id=x;
					lit->val=-size;
					id_erase.insert(make_pair(x,true));
					cout<<x<<endl;
					allocFail=false;
					break;
				} else{
					if(lit->val>size)
					{
						int remain=lit->val-size;
						lit->val=-size;
						lit->id=x;
						
						id_erase.insert(make_pair(x,true));
						cout<<x<<endl;
						
						temp.val=remain;
						temp.id=-1;
						lit++;
						s.insert(lit,temp);
						allocFail=false;
						break;
					}
				}
			}
			hebing();/*合并相邻*/			
			if(allocFail)
			{
				cout<<"NULL"<<endl;
			}else{
				x++;
			}
		}
		if(str==defragment)
		{
			for(lit=s.begin();lit!=s.end();)
			{
				temp=s.end();
				temp--;
				if(lit->val>0&&lit!=temp)
				{
					temp->val+=lit->val; 
					lit=s.erase(lit);
				}else{
					lit++;
				}
			}
		}
		if(str==erase)
		{
			int flag;
			cin>>flag;
			if(id_erase.find(flag)== id_erase.end())
			{
				cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
			}else{
				id_erase.erase(id_erase.find(flag));
				for(lit=s.begin();lit!=s.end();lit++)
				{
					if(lit->id==flag)
					{
						if(lit->val<0)
						{
							lit->val=-lit->val;
							lit->id=0;
						}
						break;
					}
				}
			}
		}
		//test();
	}
	return 0;
} 
