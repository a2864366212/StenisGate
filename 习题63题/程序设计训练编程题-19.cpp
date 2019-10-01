#include<iostream>
#include<list>
using namespace std;
list<int>id;
list<int>::iterator lit,test;
int main()
{
	int group;
	cin>>group;
	for(int g=0;g<group;g++)
	{
		int num,interval;
		cin>>num>>interval;
		for(int i=1;i<=num;i++)
		{
			id.push_back(i);
		}
		/*int circle=0;
		
			cout<<"circle "<<circle<<' '<<endl;
			for(test=id.begin();test!=id.end();test++)
			{
				cout<<(*test)<<" ";
			}
			cout<<endl;*/
		
		lit=id.begin();
		
		while(id.size()>1)
		{
			int intervalTimer=1;
			for(;;)
			{
				if(lit==id.end())
				{
					lit=id.begin();
				}
				
				if(intervalTimer%interval==0)
				{
					lit=id.erase(lit);/*delete the end what will be return */
					intervalTimer=1;
					break;
				}else{
					intervalTimer++;
					lit++;
				}
			}
			/*circle++;
			cout<<"circle "<<circle<<' '<<endl;
			for(test=id.begin();test!=id.end();test++)
			{
				cout<<(*test)<<" ";
			}
			cout<<endl;*/
		}
		cout<<(*id.begin())<<endl;
		id.erase(id.begin(),id.end());
	}
	return 0;
}
