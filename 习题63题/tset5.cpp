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
				//temp=s.end();
				//temp--;
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
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		struct space temp;
		temp.id=i;
		temp.val=t;
		s.push_back(temp);	
	}
	test();
	hebing();
	test();
	return 0;
}
