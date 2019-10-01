#include<iostream> 
using namespace std;
int c[1005]={0};
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	int l=0;
	for(int i=0;i<n;i++)
	{	
		while(1)
		{	
			//cout<<i<<endl;
			if(i+1<n)
			{
				if(c[i+1]==c[i])
				{
					i++;
					continue;
				}
				else{
					l++;
					break;
				}
			}else{
				break;
			}
		}
	}
	cout<<l+1;
	return 0;	
}
