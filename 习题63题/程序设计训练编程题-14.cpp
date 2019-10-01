#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<string,int>name_index;
pair<map<string,int>::iterator,bool>InsertJudge;
int OrderPoint[10]={25,18,15,12,10,8,6,4,2,1};
struct player
{
	string name;
	int point=0;
	int order[100]={0};
};
bool compare1(player &NowWin,player &b)
{
	if(NowWin.point!=b.point)
	{
		return NowWin.point>b.point;
	}else{
		for(int j=0;j<100;j++)
		{
			if(NowWin.order[j]!=b.order[j])
			{
				return NowWin.order[j]>b.order[j];
			}
		}
	}
	/*if(win=NowWin){
		return 1;
	}else{
		return 0;
	}*/
}
bool compare2(player &NowWin,player &b)
{
	if(NowWin.order[0]!=b.order[0])
	{
		return NowWin.order[0]>b.order[0];
	}else{
		if(NowWin.point!=b.point)
		{
			return NowWin.point>b.point;
		}else{
			for(int j=1;j<100;j++)
			{
				if(NowWin.order[j]!=b.order[j])
				{
					return NowWin.order[j]>b.order[j];
				}
			}			
		}
	}	
}
vector<player>p;
int main()
{
	int group;
	cin>>group;
	int VectorEndIndex=0;

	for(int g=0;g<group;g++)
	{
		int n;
		cin>>n;
		string name;
		for(int i=0;i<n;i++)
		{/*0代表第一名 */
			cin>>name;
			InsertJudge=name_index.insert(make_pair(name,VectorEndIndex));
			if(InsertJudge.second)
			{
				struct player temp;
				temp.name=name;
				temp.point+=OrderPoint[i];
				temp.order[i]++;
				p.push_back(temp);
				VectorEndIndex++;
			}else{
				p[ name_index[name] ].point+=OrderPoint[i];
				p[ name_index[name] ].order[i]++;
			}
		}
	}
	int winIndex=0;
	//cout<<" "<<p[0].name<<endl;
	for(int i=1;i<p.size();i++)
	{
		//cout<<" "<<p[i].name<<endl;
		if(!compare1(p[winIndex],p[i])) 
		{
			winIndex=i;
		}
	}
	cout<<p[winIndex].name<<endl;
	winIndex=0;
	//cout<<" "<<p[0].name<<endl;
	for(int i=1;i<p.size();i++)
	{
		//cout<<" "<<p[i].name<<endl;
		if(!compare2(p[winIndex],p[i])) 
		{
			winIndex=i;
		}
	}	
	cout<<p[winIndex].name;
	/*for(int i=0;i<p.size();i++)
	{
		cout<<"name "<<p[i].name<<endl
			<<"point "<<p[i].point<<endl;
			for(int j=0;j<100;j++)
			{
				cout<<"order[j] "<<j<<' '<<p[i].order[j];
				cout<<endl;
			}
	}*/
	return 0;
} 
