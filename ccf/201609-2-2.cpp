#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int flag[101]={0};
	int info[21]={0};
	for(int i=1;i<=20;i++)
	info[i]=5;
	
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>c;
		int num=0;
		vector<int>ans;
		for(int j=1;j<=100;j++)
		{
			if(flag[j]==0)
			{
				ans.push_back(j);
				num++;
			}
			if(num==c)
			break;
		}
		
			//bool findOther=true;
			for(int j=1;j<=20;j++)
			{
				if(info[j]>=c)
				{
					info[j]-=c;
					//findOther=true;
					ans.erase(ans.begin(),ans.end());
					int num=0;
					for(int k=5*(j-1)+1;k<=5*j;k++)
					{
						if(flag[k]==0)
						{
							ans.push_back(k);
							flag[k]=1;
							num++;
						}
						if(num==c) break;
					}	
					break;	
				}
			}
			for(int j=0;j<ans.size();j++)
			{
				cout<<ans[j]<<' ';
			}
			cout<<endl;
	}
	return 0;
}
