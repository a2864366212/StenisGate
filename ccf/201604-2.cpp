#include<iostream>
#include<vector>
using namespace std;
int c[16][10];
int in[4][4];
struct cell
{
	int col;//const
	int row;//non-const
};
vector<struct cell>bottom;
vector<struct cell>ans;
int main()
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<10;j++)
		{
			cin>>c[i][j];
		}
	}
	
	for(int i=0;i<10;i++)
	{
		c[15][i]=1;
	}
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>in[i][j];
		}
	}
	int begin;
	cin>>begin;
	
	
	struct cell temp;
	for(int j=0;j<4;j++)//col find
	{
		temp.col=begin-1+j;
		temp.row=-1;
		for(int i=0;i<4;i++)//row range
		{
			if(in[i][j]!=0)
			{
				temp.row=i;
				ans.push_back(temp);
			}
		}
		
		if(temp.row!=-1)
		{
			bottom.push_back(temp);
		}
			
	}
	/**/
	int repair=0;
	do
	{
		for(int i=0;i<bottom.size();i++)
		{
			bottom[i].row++;
		}
		repair++;
		
		bool isfail=false;
		
		for(int i=0;i<bottom.size();i++)
		{
			int row=bottom[i].row,col=bottom[i].col;
			
			if(c[row][col]==1)
			{
				isfail=true;
			}
		}
		if(isfail)
		{
			break;
		}
	}while(1);
	
	repair--;
	for(int i=0;i<ans.size();i++)
	{
		//ans[i].row+repair
		//ans[i].col
		c[ans[i].row+repair][ans[i].col]=1;
	}
	/*for(int i=0;i<bottom.size();i++)
	{
		int row=bottom[i].row,col=bottom[i].col;
		cout<<row-1<<' '<<col<<endl;
		//c[row-1][col]=1;
	}*/
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout<<c[i][j]<<' ';
		}
		cout<<endl;
	}
	
	return 0;
} 
