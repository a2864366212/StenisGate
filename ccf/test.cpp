#include<iostream>
#include<list>
using namespace std;

list<int>::iterator it;
void print(list<int>&a)
{
	for(it=a.begin();it!=a.end();it++)
	{
		cout<<(*it)<<' ';
	}
}
int main()
{
	list<int>stu;
	
	
	for(int i=0;i<8;i++)
	{
		stu.push_back(i);
	}

	stu.insert(stu.end(),999);
	print(stu);
	return 0;
}
