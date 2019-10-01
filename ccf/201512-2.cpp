#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
vector<int>ROW,COL;
int c[32][32];
int main()
{
	int row,col;
	cin>>row>>col;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>c[i][j];
			//c[i][j]=1+rand()%5;
			
		//	cout<<c[i][j]<<' ';
		}
		//cout<<endl;
	}
	///cout<<endl;
	/*col 0 to col-1*/
	for(int i=0;i<col;i++)
	{
		int n=1,count=c[0][i],begin=0;
		for(int j=1;j<row;j++)//end is j or j+-1
		{
			if(c[j][i]==count)
			{
				n++;
				if(j==row-1&&n>=3)
				{
					COL.push_back(i);
					COL.push_back(begin);
					COL.push_back(j);					
				}				
			}else{
				//end = j-1
				if(n>=3)
				{
					COL.push_back(i);
					COL.push_back(begin);
					COL.push_back(j-1);					
				}
				//chong zhi
				begin=j;
				n=1;
				count=c[j][i];
			}
		}
		
	}
	for(int i=0;i<row;i++)
	{
		int n=1,count=c[i][0],begin=0;
		for(int j=1;j<col;j++)//end is j or j+-1
		{
			if(c[i][j]==count)
			{
				n++;
				if(j==col-1&&n>=3)
				{
					/*for(int k=begin;k<=j;k++)
					{
						c[i][k]=0;
					}*/	
					ROW.push_back(i);
					ROW.push_back(begin);
					ROW.push_back(j);					
				}
			}else{
				//cout<<i<<' '<<j<<' '<<begin<<' '<<count<<"**"<<endl;
				//end = j-1
				if(n>=3)
				{
					/*for(int k=begin;k<j;k++)
					{
						c[i][k]=0;
					}*/
					ROW.push_back(i);
					ROW.push_back(begin);
					ROW.push_back(j-1);	
				}
				//chong zhi
				begin=j;
				n=1;
				count=c[i][j];
			}
		}
		
	}	
	for(int i=0;i<COL.size();i+=3)
	{
		for(int j=COL[i+1];j<=COL[i+2];j++)
		{
			c[j][COL[i]]=0;
			
		}
	}
	for(int i=0;i<ROW.size();i+=3)
	{
		for(int j=ROW[i+1];j<=ROW[i+2];j++)
		{
			c[ROW[i]][j]=0;
		}
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<c[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
