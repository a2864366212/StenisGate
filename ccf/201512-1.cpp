#include<iostream>
using namespace std;
void answer(int n)
{
	int ans=0;
	while(n>0)
	{
		ans+=n%10;
		n/=10;
	} 
	cout<<ans;
}
int main()
{
	int n;
	cin>>n;	
	answer(n);
	return 0;
} 

