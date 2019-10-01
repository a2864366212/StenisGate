#include<iostream>
#include<cstring>
using namespace std;
int a[1000000];
bool sum(string &l,string &s)
{/* <d+c> = d+c-a  <b+z> = b+z-a-a -26*/
	for(int i=0;i<l.size();i++)
	{
		a[i]= l[i]-'a';
		//cout<<a[i]<<' ';
	}
	//cout<<endl;
	for(int i=0;i<s.size();i++)
	{
		 a[l.size()-1-i]+=s[s.size()-1-i]-'a';
		 //cout<<a[i]<<' ';
	}
	//cout<<endl;
	for(int i=l.size()-1;i>= 1;i--)
	{
		//cout<<a[l.size()-1]<<"6666";
		if(a[i]>('z'-'a'))
		{
			a[i]-=26;
			l[i]= a[i]+'a';
			a[i-1]+=1;
		}else{
			l[i]=a[i]+'a';
		}
	}
		if(a[0]>('z'-'a'))
		{//cout<<a[l.size()-1]<<"6666";
			a[0]-=26;
			l[0]=a[0]+'a';
			return 1;/*½øÎ»ÁË*/
		}else{//cout<<a[l.size()-1]<<"6666";
			l[0]=a[0]+'a';
			return 0;
		}
}
int main()
{
	int n;
	cin>>n;	
	string l,s; 
	for(int i=0;i<n;i++)
	{
		cin>>l>>s;
		if(l.size()<s.size()) swap(l,s);
		
		if(sum(l,s))
		{
			cout<<'a'<<l<<endl;
		}else{
			cout<<l<<endl;
		}
	}
	return 0;
} 
