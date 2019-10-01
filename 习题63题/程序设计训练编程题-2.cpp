#include<iostream>
using namespace std;
void Spell(int sum)
{
	switch(sum)
	{
		case 0:cout<<"ling";break;
		case 1:cout<<"yi";  break;
		case 2:cout<<"er";  break;
		case 3:cout<<"san"; break;
		case 4:cout<<"si";  break;
		case 5:cout<<"wu";  break;
		case 6:cout<<"liu"; break;
		case 7:cout<<"qi";  break;
		case 8:cout<<"ba";  break;
		case 9:cout<<"jiu"; break;
		default:break;
	}
}
void Print(int sum,int ceng)
{
	if(sum==0)
	{
		return ;
	}else{
		Print(sum/10,ceng+1);
		Spell(sum%10);
				
		if(ceng!=0)
		cout<<" ";
	}	
}
void Print(int *a,int sum)
{
	int max_pos=0;
	for(int i=0;;i++)
	{
		 max_pos=i;
		 a[i]=sum%10;
		 sum/=10;
		 if(sum==0)
		 {
		 	break;
		 }
	}
	for(int i=max_pos;i>=0;i--)
	{
		if(i==max_pos) Spell(a[i]);
		else{
			cout<<" ";
			Spell(a[i]);
		}
	}	
}
int a[2000];
int main()
{
	char ch;
	int sum=0;
	while( (ch=getchar()) != EOF)
	{
		sum+=ch-'0';
	}
	Print(a,sum);
	return 0;
}
