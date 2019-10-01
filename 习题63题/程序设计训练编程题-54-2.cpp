#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string::iterator it;
void ReversePrint(string &str)
{
	for(it=str.end()-1;it>=str.begin();it--)
	{
		cout<<(*it);
	}
	str.erase(str.begin(),str.end());
}
int main()
{
	int group;
	scanf("%d",&group);
	char ch;
	ch=getchar();
	for(int g=0;g<group;g++)
	{
		string str;
		while(1)
		{
			if(scanf("%c",&ch)==EOF||ch=='\n')
			{
				ReversePrint(str);
				printf("\n");
				break;
			}else{
				if(ch==' ')
				{
					ReversePrint(str);
					printf(" ");
				}else{
					str+=ch;
					//cout<<str<<endl;
				}
			}
		}
	}
	return 0;
} 
