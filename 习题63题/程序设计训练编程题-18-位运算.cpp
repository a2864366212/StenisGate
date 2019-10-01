#include<iostream>
#include<map>
using namespace std;

map<string,int>TwotoTen;
map<string,int>::iterator mit;
pair<map<string,int>::iterator,bool>InsertJudge;

void TenToTwo(int Ten,string &result)
{
	 for(int i=1;i<=8;i++)
	 {
	 	if((Ten&128)) result+='1';
	 	else result+='0';
	 	Ten=Ten<<1;
	 } 
}
int main()
{  
	
	for(int i=0;i<=255;i++)
	{	/*create table*/
		string temp; 
		TenToTwo(i,temp);
		TwotoTen.insert(make_pair(temp,i)); 
	}
	string test,sub;
	cin>>test;
	int pos=0;
	for(int i=1;i<=4;i++)
	{
		sub=test.substr(pos,8);
		
		if(i==1)
		{
			cout<<TwotoTen[sub];
		}else{
			cout<<'.'<<TwotoTen[sub];
		}
		pos+=8;
	}
	
	/*int group;
	cin>>group;
	for(int g=0;g<group;g++)
	{
		
	}*/
	return 0;
} 
