#include<iostream>
using namespace std;
int main()
{
	int d[1000]={0},m[1000]={0};
	for(int n=1;;n++)
	{
		d[n]=n*(n+1)/2;
		//cout<<n<<endl;
		m[n]=m[n-1]+n*n;
		if(d[n]>10000)
		break; 
	}
	int day;
	while(cin>>day)
	{
		/*n*(n+1)/2*/
		int pos;
		for(int i=1;i<=140;i++)
		{
			if(d[i]<day&&day<=d[i+1])
			{
				pos=i;
			}
		}
		
		cout<<day<<' '<<m[pos]+(day-d[pos])*(pos+1)<<endl;
	}
	return 0;
} 
