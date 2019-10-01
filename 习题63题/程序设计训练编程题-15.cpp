#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
set<int>nonrepeat;
set<int>::reverse_iterator sit;
map<int,int>point_order;
map<int,int>::iterator mit;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		a[i]=temp;
		nonrepeat.insert(temp);
	}
	int pos=1;
	for(sit=nonrepeat.rbegin();sit!=nonrepeat.rend();sit++)
	{
		point_order.insert(make_pair((*sit),pos));
		pos++;
	}

	for(int i=0;i<n;i++)
	{
		if(i==0)
		cout<<point_order[ a[i] ];
		else{
			cout<<" "<<point_order[ a[i] ];
		}
	}
	return 0;
}
