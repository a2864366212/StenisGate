#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string a;
	while(cin>>a)
	{
		int pos=a.find('B');
		int flag=0;
		for(int i=pos+1;i<a.size();i++)
		{
			if(a[i]==')') flag++;
			else flag--;
		}
		cout<<flag<<endl;		
	}
	return 0;
}

