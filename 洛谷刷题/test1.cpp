#include<iostream>
#include<cstdlib>
using namespace std;

int ans[21][21][21];/*0~20 index*/
int fill(int a,int b,int c)
{
	if(a<=0||b<=0||c<=0){
		return 1;
	}
	if(a>20||b>20||c>20){
		return fill(20,20,20);
	}
	if(a<b&&b<c){
		return fill(a,b,c-1)+
		fill(a,b-1,c-1)-fill(a,b-1,c);
	}
	return fill(a-1,b,c)+fill(a-1,b-1,c)+
	fill(a-1,b,c-1)-fill(a-1,b-1,c-1);
}
int main()
{	
	int i=10000000;
	cout<<i;
	return 0;
}
