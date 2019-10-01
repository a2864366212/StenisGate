#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<int,vector<int> >test;
int main ()
{
	
	for(int i=0;i<5;i++)
	{
		vector<int>temp;
		for(int j=0;j<i+3;j++)
		{
			temp.push_back(j);	
		}
		test.insert(make_pair(i,temp));
	}
	
	return 0; 
}
