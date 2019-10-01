#include<iostream>
using namespace std;
int c[1005][1005];
int main()
{
	int row,col;
	cin>>row>>col;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>c[i][j];
		}
	}
	for(int i=col-1;i>=0;i--)
	{
		for(int j=0;j<row;j++)
		{
			cout<<c[j][i]<<' ';
		}
			cout<<endl;
	}
	return 0;	
}
