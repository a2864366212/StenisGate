#include<iostream>
#include<list>
using namespace std;
struct carpet
{
	int x1,y1,x2,y2;
};
list<struct carpet>ans;
list<struct carpet>::reverse_iterator lit;
bool isinclude(int x1,int y1,int x2,int y2,int x,int y)
{
	if((x1<=x&&x<=x2)&&(y1<=y&&y<=y2)) return true;
	else return false;
}
int main()
{
	int n;
	cin>>n;
	int x1,y1,x2,y2;
	for(int i=0;i<n;i++)
	{
		cin>>x1>>y1>>x2>>y2;
		struct carpet temp;
		temp.x1=x1;
		temp.y1=y1;
		temp.x2=x2+x1;
		temp.y2=y2+y1;
		ans.push_back(temp);
	}
	
	int x,y;
	cin>>x>>y;
	int id=n;
	bool canfind=false;
	for(lit=ans.rbegin();lit!=ans.rend();lit++,id--)
	{
		if( isinclude(lit->x1, lit->y1, lit->x2, lit->y2, x, y) )
		{
			canfind=true;
			cout<<id;
			break;
		}
	}
	if(!canfind)
	{
		cout<<-1;
	}
	return 0;
} 

