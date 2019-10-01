#include<iostream>
#include<map>
using namespace std;
map<int,string>point_id;
map<int,string>::iterator it;
int main()
{
	int n;
	cin>>n;
	string name,id;
	for(int i=0;i<n;i++)
	{
		int point;
		cin>>name>>id>>point;
		name+=' ';
		name+=id;
		point_id.insert(make_pair(point,name));
	}
	it=point_id.end();
	it--;
	cout<< it->second<<endl;
	cout<< (point_id.begin())->second;
	return 0;
}
