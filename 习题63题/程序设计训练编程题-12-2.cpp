#include<iostream>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<map>
using namespace std;

map<string,int>name_Index;
map<string,int>::iterator mit;
pair<map<string,int>::iterator,bool>InsertJudge;
stringstream ss;
void stringtoint(int &a,string & s)
{
	ss<<s;
	ss>>a;
	ss.clear();
	ss.str("");
}
struct team
{
	string name;
	int point=0;//积分 递减
	int GoalDifference=0;
	int GoalNum=0;
	/*按照净胜球递减以及进球数递减方式排名*/
};
bool IsCount(char ch)
{
	if('0'<=ch&&ch<='9')
	return true;
	else return false;
}
bool IsLetter(char ch)
{
	if(  ('a'<=ch&&ch<='z') || ('A'<=ch&&ch<='Z') )
	{
		return true;
	}else return false;
}
bool compare(team a ,team b)
{
	if(a.point!=b.point)
	{
		return a.point >b.point;
	}else{
		if(a.GoalDifference!=b.GoalDifference)
		return a.GoalDifference>b.GoalDifference;
		else{
			return a.GoalNum>b.GoalNum;
		}
	}
	//按照积分递减、净胜球递减以及进球数递减方式排名
}
bool compare2(team a ,team b)
{
	return a.name<b.name;
}
int main()
{
	int n;
	cin>>n;
	string name;
	team t[n];
	for(int line=0;line<n;line++)
	{
		fflush(stdin);
		getline(cin,name);
		/*int startpos,endpos;
		for(int i=name.size()-1;i>=0;i--)
		{
			if(IsLetter(name[i]))
			{
				endpos=i;
				break;
			}
		}
		for(int i=0;i<name.size();i++)
		{
			if(IsLetter(name[i]))
			{
				startpos=i;
				break;
			}
		}
		name=name.substr(startpos,endpos-startpos+1);*/
		t[line].name=name;
		name_Index.insert(make_pair(name,line));
	}
	/*for(mit=name_Index.begin();mit!=name_Index.end();mit++)
	
		cout<<(*mit).first<<" "<<(*mit).second<<endl;
	
	for(int i=0;i<n;i++)
	{
		cout<<t[i].name<<1<<endl;
	}*/
	string information;
	string a,b;
	for(int line=0;line<n*(n-1)/2;line++)
	{
		string c,d;
		fflush(stdin);
		information.erase(information.begin(),information.end());
		if(line<n*(n-1)/2-1)
		getline(cin,information);
		else{
			char ch;
			while((ch=getchar())!=EOF)
			{
				information+=ch;
			}
		}
		a=information.substr(0, information.find('-')) ;
		int pos;
		d=information.substr(information.find(':')+1,information.size()-1-information.find(':')) ;
		c=information.substr(information.rfind(' ')+1,information.find(':')-1-information.find(' ')) ;		
		/*for(int i=information.size()-1;i>=0;i--)
		{
			if(IsCount(information[i]))
			{
				d+=	information[i];			
			}else{
				reverse(d.begin(),d.end());
				pos=i;
				break;	
			}
		}
		for(int i=pos-1;i>=0;i--)
		{
			if(IsCount(information[i]))
			{
				c+=	information[i];			
			}else{
				reverse(c.begin(),c.end());
				pos=i-1;
				break;	
			}			
		}*/
		/*pos-=1;
		for(int i=pos;i>=0;i--)
		{
			if(IsLetter(information[i]))
			{
				pos=i;
				break;
			}
		}*/
		b= information.substr(information.find('-')+1,information.rfind(' ')-1-information.find('-'));
		/*for(int j=0;j<n;j++)
		{
			//cout<<"t[j].name j "<<t[j].name<<' '<<j<<endl;
			if(information.find(t[j].name,information.find('-')+1)!=string::npos)
			{
				b=t[j].name;
				break;
			}
		}*/
		int cc,dd;
		stringtoint(cc,c);
		stringtoint(dd,d);
		if(cc>dd)
		{
			t[ name_Index[a] ].point+=3;
			t[ name_Index[a] ].GoalDifference+= cc-dd;
			t[ name_Index[a] ].GoalNum+=cc;
			t[ name_Index[b] ].GoalDifference+= dd-cc;
			t[ name_Index[b] ].GoalNum+=dd;	
				cout<<"*******************"<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<cc<<" "<<dd<<endl;		
			continue;
		}
		if(cc==dd)
		{
			t[ name_Index[a] ].point+=1;
			t[ name_Index[a] ].GoalDifference+= cc-dd;
			t[ name_Index[a] ].GoalNum+=cc;			
			t[ name_Index[b] ].point+=1;
			t[ name_Index[b] ].GoalDifference+= dd-cc;
			t[ name_Index[b] ].GoalNum+=dd;	
				cout<<"*******************"<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<cc<<" "<<dd<<endl;			
			continue;
		}
		if(cc<dd)
		{
			t[ name_Index[a] ].GoalDifference+= cc-dd;
			t[ name_Index[a] ].GoalNum+=cc;	
			t[ name_Index[b] ].point+=3;
			t[ name_Index[b] ].GoalDifference+= dd-cc;
			t[ name_Index[b] ].GoalNum+=dd;	
				cout<<"*******************"<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<cc<<" "<<dd<<endl;
			continue;
		}
	}
	/*for(int i=0;i<n;i++)
	{
		cout<<"name "<<t[i].name<<'1'<<endl
			<<"Point "<<t[i].point<<endl
			<<"goaldifference "<<t[i].GoalDifference<<endl
			<<"goal num "<<t[i].GoalNum<<endl;
	}*/
	sort(t,t+n,compare);
	sort(t,t+n/2,compare2);
	for(int i=0;i<n/2;i++)
	{
		if(i==0)
		cout<<t[i].name;
		else
		cout<<endl<<t[i].name;
	}
	return 0;
} 

