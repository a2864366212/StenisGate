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
	int point=0;//���� �ݼ�
	int GoalDifference=0;
	int GoalNum=0;
	/*���վ�ʤ��ݼ��Լ��������ݼ���ʽ����*/
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
	//���ջ��ֵݼ�����ʤ��ݼ��Լ��������ݼ���ʽ����
}
bool compare2(team a ,team b)
{
	return a.name<b.name;
}
int main()
{
	int n;
	cin>>n;
	char ch;
	ch=getchar();
	 
	string name;
	team t[n];
	for(int line=0;line<n;line++)
	{
		
		getline(cin,name);
		t[line].name=name;
		name_Index.insert(make_pair(name,line));
	}
	/*for(mit=name_Index.begin();mit!=name_Index.end();mit++)
	
		cout<<(*mit).first<<" "<<(*mit).second<<endl;
	
	for(int i=0;i<n;i++)
	{
		cout<<t[i].name<<1<<endl;
	}*/

	string a,b;
	for(int line=0;line<n*(n-1)/2;line++)
	{
		string information;
		string c,d;
		fflush(stdin);
		getline(cin,information);
		
		a=information.substr(0, information.find('-'));
		b=information.substr(information.find('-')+1,information.rfind(' ')-1-information.find('-'));
		d=information.substr(information.find(':')+1,information.size()-1-information.find(':')) ;
		c=information.substr(information.rfind(' ')+1,information.find(':')-1-information.find(' ')) ;		
		
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
			//	cout<<"*******************"<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<cc<<" "<<dd<<endl;		
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
			//	cout<<"*******************"<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<cc<<" "<<dd<<endl;			
			continue;
		}
		if(cc<dd)
		{
			t[ name_Index[a] ].GoalDifference+= cc-dd;
			t[ name_Index[a] ].GoalNum+=cc;	
			t[ name_Index[b] ].point+=3;
			t[ name_Index[b] ].GoalDifference+= dd-cc;
			t[ name_Index[b] ].GoalNum+=dd;	
			//	cout<<"*******************"<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<cc<<" "<<dd<<endl;
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

