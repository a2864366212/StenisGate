#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int c[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>c[i][j];
		}
	}
	for(int line=1;line<=2*n-1;line++)
	{
		//cout<<endl<<line<<" 666666666 "<<endl;
		// duijiaoxian :: xpos ypos : i+j== start x + start y
		if(line==1)
		{
			cout<<c[0][0];
			continue;
		} 
		if(line<=n)
		{
			if(line%2==0)
			{
				//right up to left down : start i = 0;start j==n-1
				for(int i=0;i<=line-1;i++)
				{
					//cout<<i<<' '<<line-1-i<<endl;
					cout<<' '<<c[i][line-1-i];	
				}
				
			}else{
				//left down to right up : start i=n-1;start j==0
				for(int j=0;j<=line-1;j++)
				{
					//cout<<line-1-j<<' '<<j<<endl;
					cout<<' '<<c[line-1-j][j];
				}
			}			
		}
		else{
			if(line%2==0)
			{
				//start i=line-n;start j=n-1
				for(int j=n-1;j>=line-n;j--)
				{
					cout<<' '<<c[line-1-j][j];
				}
			}else{
				//start i=n-1 ; start j=line - n
				for(int i=n-1;i>=line-n;i--)
				{
					cout<<' '<<c[i][line-1-i];
				}
			}
		} 
	}
	return 0;
} 
