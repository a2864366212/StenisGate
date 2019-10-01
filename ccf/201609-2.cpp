#include<iostream>
#include<queue>
using namespace std;
struct cell
{
	queue<int>line_index;
};
int main()
{
	int n;
	cin>>n;
	int flag[101]={0};
	vector<struct cell>ans;
	struct cell temp;
	queue<int>index;

	for(int i=1;i<=20;i++)
	{
		index.push(i);
		//temp.line_index.push_back(i);
	}	
	temp.line_index=index;
	
	for(int i=0;i<6;i++)
	{
		/*i-1*/
		ans.push_back(temp);
	}
	
	int judge[6]={0};
	
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>c;
		int line=0;	
		int min=9999;
		for(int j=c;j<=5;j++)
		{
			index=ans[j].line_index;
			judge[j]=index.top();
			if(min>judge[j])
			{
				min=judge[j];
			}
		}
		for(int j=5*(line-1)+1;j<=5*line;j++)
		{
			
		}
	}
	return 0;
} 
