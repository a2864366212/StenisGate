#include<iostream>
#include<map>
using namespace std;
map<int,int>sum,s;
map<int,int>::iterator it,it2;
int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)break;
		int a[n],ss[n*(n-1)/2];
		for(int i=0;i<n*(n-1)/2;i++)
		{
			cin>>ss[i];
			sum.insert(make_pair(ss[i],1));
		}
		it=sum.begin();
		it++;it++;
		for(;it!=sum.end();it++)
		{
			a[0]=ss[0]+ss[1]- it->first;
			//cout<<"a[0]"<<a[0]<<"s[0]"<<s[0]<<' '<<s[1]<<' '<<it->first<<endl;
			if(a[0]%2!=0)
			{
				continue;
			}else a[0]/=2;
			
			bool isfail=false;
			int min;
			
			s=sum;
			for(int j=1;j<=n-1;j++)/*a0----a1 a2 a3*/
			{
				min=s.begin()->first;
				a[j]=min-a[0];
				
				if(a[j]<=0)
				{
					isfail=true;
					break;	
				} 
				for(int k=0;k<j;k++)
				{
					if(s.find(a[k]+a[j])!=s.end())
					{
						s.erase( s.find(a[k]+a[j]) );
					}
				}
			
				/*for(int i=0;i<n;i++)
				{
					cout<<a[i]<<' ';
				}
				cout<<endl;*/
			}
			if(s.size()==0)break;	
		}
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<' ';
		}		
		cout<<endl;
		sum.erase(sum.begin(),sum.end());
	}
	return 0;
} 


