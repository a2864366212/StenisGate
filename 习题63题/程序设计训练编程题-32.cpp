#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct person
{
	string name;
	vector<string>book;
}; 
vector<person> list;
vector<string>::iterator vit;

map<string,int>name_nameindex;
map<string,int>::iterator it;
pair<map<string,int>::iterator,bool>insertjudge;

bool isname(char ch)
{
	if('a'<=ch&&ch<='z')
	{
		return 1;
	}else{
		return 0;
	}
}
bool include(string&compare,const string&sample)
{
	if(sample.size()<compare.size())
	{
		return false; 
	}
	if(sample.find(compare)!=string::npos)
	{
		if(sample.find(compare)==sample.size()-compare.size())
		{
			return true;
		} 
	}
	return false;
}
bool cmp(string a, string b)
{
	if(a.size()!=b.size())
	{
		return a.size()<b.size();
	}else return a<b;
}
bool cmpname(struct person a,struct person b)
{
	return a.name<b.name;
}
int main()
{
	int n;
	cin>>n;
	string temp,name;
	int nameindex=0;
	while(cin>>temp)
	{
		if(isname(temp[0]))
		{
			name=temp;
			insertjudge=name_nameindex.insert(make_pair(name,nameindex));
			if(insertjudge.second){
				nameindex++;
				struct person p;
				p.name=name;
				list.push_back(p);
			}
			int nn;
			cin>>nn;
		}else{
			list[name_nameindex[name]].book.push_back(temp); 
		}
	}
	for(int i=0;i<list.size();i++)
	{
		for(int j=0;j<list[i].book.size()-1;j++)
		{
			for(int k=j+1;k<list[i].book.size();k++)
			{
				if(include( list[i].book[j], list[i].book[k]) )
				{
					list[i].book[j]=" ";
				}else{
					if(include( list[i].book[k], list[i].book[j]) )
					{
						list[i].book[k]=" ";
					}
				}
			}
		} 
	}
	cout<<list.size()<<endl;
	sort(list.begin(),list.end(),cmpname);
	for(int i=0;i<list.size();i++)
	{
		sort(list[i].book.begin(),list[i].book.end(),cmp);
		cout<<list[i].name<<' ';
		int num=0;
		for(int j=0;j<list[i].book.size();j++)
		{
			if(list[i].book[j]!=" ")
			num++;
		}
		cout<<num<<' ';
		for(int j=0;j<list[i].book.size();j++)
		{
			if(list[i].book[j]!=" ")
			cout<<list[i].book[j]<<" ";
		}		
		cout<<endl;
	}
	return 0;
}
