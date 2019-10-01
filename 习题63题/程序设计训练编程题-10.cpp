#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
char translate(const char &ch)
{
	int delta = ch-'A'-5;
	if(delta<0)
	{
		delta+=26;
	}
	return 'A'+delta;
	/*'A'+
	'Z'-'A'
	DELTA= ch-'A'-5
	xy z a bcde f
	f-5=a;
	ch=d  delta d=3-5=-2
	delta y=24
	24=26-2*/
}
bool IsLetter(char ch)
{
	if('A'<=ch&&ch<='Z') return true;
	else return false;
}
int main()
{
	char t[26];
	int line=0;
	string START="START",END="END",ENDOFINPUT="ENDOFINPUT";
	for(char ch='A';ch<='Z';ch++)
	{
		int i=ch-'A';
		t[i]=translate(ch);
	}
	string SEflag;
	string text;
	while(1)
	{
		cin>>SEflag;
		if(SEflag==ENDOFINPUT)
		{
			break;
		}
		
		if(SEflag==START)
		{
			char ch=getchar();
			getline(cin,text);
			for(int i=0;i<text.size();i++)
			{
				if(IsLetter(text[i]))
				text[i]=t[ text[i]-'A' ];
			}
		}
		cin>>SEflag;
		if(line==0)
		{
			line++;
			cout<<text;
		}else{
			cout<<text<<endl;
		}
	}
	return 0;
}
