#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n][n];
	int count=1;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j>=0;j--)
		{
			//cout<<"row "<<j<<"col "<<i+1-j<<endl;
			a[j][i-j]=count;
			count++;
		}
	}	
	/*00 01 02 03 04
	10 11 12 13 
	20 21 22
	30 31 
	40*/
	for(int i=0;i<n;i++)
	{
		if(i!=0)
		cout<<endl;	
			
		for(int j=0;j<n-i;j++)
		{
			if(j==0)
			cout<<a[i][j];
			else
			cout<<' '<<a[i][j];
		}

	}
	return 0;
}
