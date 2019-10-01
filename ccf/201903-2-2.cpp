#include<iostream>
#include<cstring>
#include<sstream>
#include<list>
#include<vector>
using namespace std;
stringstream ss;
int stringtoint(string s)
{
	int result;
	ss<<s;
	ss>>result;
	ss.clear();
	ss.str("");
	return result;
}

struct node
{
	int count=-1;
	char fuhao='#';
};

void answer()
{
	string s;
	cin>>s;
	list<struct node>solution;
	vector<int>index;
	for(int i=0;i<s.size();i++)
	{
		char ch=s[i];
		if(ch=='+'||ch=='-'||ch=='x'||ch=='/')
		{
			index.push_back(i);
		}
	}
	int strbegin=0;
	struct node temp;
	for(int i=0;i<index.size();i++)
	{
		temp.count=stringtoint(s.substr(strbegin,index[i]-strbegin));
		solution.push_back(temp);
		temp.count=-1;
		temp.fuhao=s[index[i]];
		solution.push_back(temp);
		temp.fuhao='#';
		strbegin=index[i]+1;
	}
	int l=s.size()-strbegin;
	
	temp.count=stringtoint(s.substr(strbegin,l));
	solution.push_back(temp);
	temp.count=-1;
	
	list<struct node>::iterator it1 ,it2,it3,endflag;
	it1= solution.begin();
	it2= solution.begin();
	it3= solution.begin();
	/*for(endflag=solution.begin();endflag!=solution.end();endflag++)
	{
		cout<<endflag->count<<"test "<<endflag->fuhao<<endl;
	}*/
	int ans = it1->count;
	it2++;
	it3=it2;
	it3++;
	
	for(;;)
	{
		char ch=it2->fuhao;
		int c=it3->count;
		
		endflag=it3;
		endflag++;
		if(endflag==solution.end())
		{
			if(ch=='x'||ch=='/')
			{
				if(ch=='x')
				{
					it1->count*=it3->count;
				}else{
					it1->count/=it3->count;
				}
				solution.erase(it2);
				solution.erase(it3);
			}
			break; 
		}
		
		if(ch=='+'||ch=='-')
		{
			it1=it3;
			it2=it3;
			it2++;
			it3=it2;
			it3++;
		}else{
			if(ch=='x')
			{
				it1->count*=it3->count;
			}else{
				it1->count/=it3->count;
			}
			solution.erase(it2);
			it2=it3;
			it2++;
			solution.erase(it3);
			it3=it2;
			it3++;  
		}
	}
	
	it1= solution.begin();
	it2= solution.begin();
	it3= solution.begin();
	/*for(endflag=solution.begin();endflag!=solution.end();endflag++)
	{
		cout<<endflag->count<<"test "<<endflag->fuhao<<endl;
	}*/
	it2++;
	it3=it2;
	it3++;
		
	for(;;)
	{
		char ch=it2->fuhao;
		int c=it3->count;
		
		endflag=it3;
		endflag++;
		if(endflag==solution.end())
		{
			if(ch=='+')
			{
				it1->count+=c;
			}else{
				if(ch=='-')
				it1->count-=c;
			}
			break;
		}
		if(ch=='+')
		{
			it1->count+=c;
		}else{
			if(ch=='-')
			it1->count-=c;
		}
		
		solution.erase(it2);
		it2=it3;
		it2++;
		solution.erase(it3);
		it3=it2;
		it3++;
	}	
	if(it1->count==24)
	cout<<"Yes";
	else cout<<"No";
			
	cout<<endl;
} 
int main()
{
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		answer();
	}
	return 0;
}
