#include<iostream>
#include<cstring>
#include<algorithm>
#include<list>
using namespace std;
list<char>::iterator NowBegin,it,temp;
list<char>str;
void ReversePrint(list<char>&str)
{
	it=str.end();
	it--;
	for(;it!=NowBegin;it--)
	{
		cout<<(*it);
	}
	cout<<(*NowBegin);
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
					str.push_back(ch);
					//cout<<str<<endl;
					if(MeetBlank)
					{
						NowBegin=str.end();/*µü´úÆ÷Ê§Ð§£¿£¿£¿*/
						NowBegin--;
						MeetBlank=false;
					}
				}
			}
		}
	}
	return 0;
} 
