#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

map<int,vector<int> >time_id;
map<int,vector<int> >::iterator it;
pair<map<int,vector<int> >::iterator,bool>judge;
int key[1000]={0};
bool cmp(int a,int b)
{
		/*+id 取  -id 还 */
	if(a<0&&b<0)
	return a>b;
	else
	return a<b; 
	//-1 -2 -3 - 4- -  ++ + + ++ 
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		key[i]=i+1;
	}
	
	for(int i=0;i<k;i++)
	{
		int id,begin,end;
		cin>>id>>begin>>end;
		end+=begin;
		
		vector<int>temp;
		temp.push_back(id);
		/*+id 取  -id 还 */
		judge = time_id.insert(make_pair(begin,temp));
		if(!judge.second)
		{
			time_id[begin].push_back(id);
		}
		temp[0]=-id;
		
		judge = time_id.insert(make_pair(end,temp));
		if(!judge.second)
		{
			time_id[end].push_back(-id);
		}
		
	}
	
	for(it=time_id.begin();it!=time_id.end();it++)
	{
		sort( (*it).second.begin() , (*it).second.end() , cmp);
		
		cout<<"id"<<(*it).first<<' ';
		for(int i=0;i<(*it).second.size();i++)
		{
			cout<<(*it).second[i]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
} 
