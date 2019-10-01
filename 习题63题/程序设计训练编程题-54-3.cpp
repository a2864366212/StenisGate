#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string::iterator NowBegin,it;
void ReversePrint(string &str)
{
	for(it=str.end()-1;it>=NowBegin;it--)
	{
		cout<<(*it);
	}
	//str.erase(str.begin(),str.end());
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
		NowBegin=str.begin();
		bool MeetBlank=false;
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
					MeetBlank=true;
					ReversePrint(str);
					printf(" ");
				}else{
					str+=ch;
					//cout<<str<<endl;
					if(MeetBlank)
					{
						NowBegin=str.end()-1;/*µü´úÆ÷Ê§Ð§£¿£¿£¿*/
					}
				}
			}
		}
	}
	return 0;
} 
