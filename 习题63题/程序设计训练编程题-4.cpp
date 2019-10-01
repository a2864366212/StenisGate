#include<iostream>
#include<cstring>
using namespace std;
int w[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char Inspect(int yushu)
{
	switch(yushu)
	{
		case 0: return '1';break;
		case 1: return '0';break;
		case 2: return 'X';break;
		case 3: return '9';break;
		case 4: return '8';break;
		case 5: return '7';break;
		case 6: return '6';break;
		case 7: return '5';break;
		case 8: return '4';break;
		case 9: return '3';break;
		case 10:return '2';break;
		default:break;
	}
}
int Mod(string & a )
{
	int sum=0;
	for(int i=0;i<17;i++)
	{
		sum+=(a[i]-'0')*w[i];
	}
	return sum%11;
}
int main()
{
	string a;
	char ch;
	int line=0;
	while(1)
	{
		ch=getchar();
		if(ch=='\n')
		{
			if(a[a.size()-1]==Inspect(Mod(a)))
			{
				if(line!=0)
				cout<<endl<<1;
				else{
					cout<<1;
					line++;
				}
			}
			else{
				if(line!=0)
				cout<<endl<<0;
				else{
					cout<<0;
					line++;
				}
			} 
			a.erase(a.begin(),a.end());
			continue;
		}
		else
		{
			if(ch=='-'/*-1*/)
			{
				break;
			}
			else{
				a.push_back(ch);
			}
		}
	}
	
	return 0; 
}
