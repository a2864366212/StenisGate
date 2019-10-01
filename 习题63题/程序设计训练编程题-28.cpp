#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
map<string,bool>strategy_result;/*true ´ú±í ×ó±ßÓ®*/
struct player
{
	int  numofwin=0;
	int  numofdraw=0;
	int  numoflose=0;
	int  j=0;
	int  c=0;
	int  b=0;
}pa,pb;
struct g
{
	char gesture;
	int num;
};
bool com(struct g a,struct g b)
{
	if(a.num!=b.num)
	{
		return a.num>b.num;
	}else{
		return a.gesture<b.gesture;
	}
}
int main()
{
	strategy_result.insert(make_pair("JB",1));
	strategy_result.insert(make_pair("BJ",0));
	strategy_result.insert(make_pair("JC",0));
	strategy_result.insert(make_pair("CJ",1));
	strategy_result.insert(make_pair("BC",1));
	strategy_result.insert(make_pair("CB",0));
	
	int n;
	cin>>n;
	string strategy="aa";
	char agesture,bgesture;
	for(int i=0;i<n;i++)
	{
		cin>>agesture>>bgesture;
		strategy[0]=agesture;
		strategy[1]=bgesture;
		if(agesture==bgesture)
		{
			pa.numofdraw++;
			pb.numofdraw++;
		}else{
			if(strategy_result[strategy])
			{/*pa is winner*/
				pa.numofwin++;
				pb.numoflose++;
				if(agesture=='J')pa.j++;
				if(agesture=='C')pa.c++;
				if(agesture=='B')pa.b++;
			}else{
				pb.numofwin++;
				pa.numoflose++;
				if(bgesture=='J')pb.j++;
				if(bgesture=='C')pb.c++;
				if(bgesture=='B')pb.b++;				
			}
		}
	}
	cout<<pa.numofwin<<' '<<pa.numofdraw<<' '<<pa.numoflose<<endl
		<<pb.numofwin<<' '<<pb.numofdraw<<' '<<pb.numoflose<<endl;

	struct g ges[3];
	ges[0].gesture='J';
	ges[0].num=pa.j;
	ges[1].gesture='C';
	ges[1].num=pa.c;
	ges[2].gesture='B';
	ges[2].num=pa.b;
	sort(ges,ges+3,com);
	cout<<ges[0].gesture<<' ';
	
	ges[0].gesture='J';
	ges[0].num=pb.j;
	ges[1].gesture='C';
	ges[1].num=pb.c;
	ges[2].gesture='B';
	ges[2].num=pb.b;
	sort(ges,ges+3,com);
	cout<<ges[0].gesture;	
	return 0;
}

