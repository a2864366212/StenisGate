	/*0 1 2 3 4 5 6 
	0 1 2 3 4 5  6  0 1 2 3 4 5 6  0 1  2 3 4 5 6
	s e 
	6 1
	1 6
	(s+x)%7==e
	s+x-7=e
	x min =7+e-s=8-6=2
	x min =e-s
	s+(x min + 7*k)%7==e
	num of day == x+1 =3  6 0 1 
	x=x min + 7*k */
#include<iostream>
#include<cstring>
#include<map>
#include<cmath>
using namespace std;
map<string,int>str_int;
string str[7]={"monday","tuesday","wednesday","thursday"
				,"friday","saturday","sunday" };
int main()
{	
	for(int i=0;i<7;i++)
	{
		str_int.insert(make_pair(str[i],i));
	}
	int n;
	cin>>n;
	string s,e;
	double l,r,xmin;
	for(int i=0;i<n;i++)
	{
		cin>>s>>e>>l>>r;
		if(str_int[s]>str_int[e])
		{
			xmin=7+str_int[e]-str_int[s];
		}else{
			xmin=str_int[e]-str_int[s];
		}
		//x+1=min+7*k+1 k>=0
		//l<=min+7*k+1<=r    (l-xmin-1)/7  r-1-min
		int kmin=ceil( (l-xmin-1)/7 );
		int kmax=floor( (r-xmin-1)/7 );
		//2+7*k   2 5  33 35<5,4>
		if(kmin==kmax&&kmax>=0)
		{
			cout<<xmin+7*kmax+1<<endl;
		}else{
			if(kmin<kmax&&kmin>=0)
			cout<<"many"<<endl;
			else cout<<"impossible"<<endl;
		}
	}
	return 0;
} 

