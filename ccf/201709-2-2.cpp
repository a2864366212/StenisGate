#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

map<int,vector<int> >time_id;
map<int,vector<int> >::iterator it;
pair<map<int,vector<int> >::iterator,bool>judge;
int key[1000]={0};
map<int,int>id_index;

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
		id_index.insert(make_pair(i+1,i));
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
		/*
		cout<<"id"<<(*it).first<<' ';
		for(int i=0;i<(*it).second.size();i++)
		{
			cout<<(*it).second[i]<<" ";
		}
		cout<<endl;
		*/
	}
	
	for(it=time_id.begin();it!=time_id.end();it++)
	{
		/*+id 取  -id 还 */
		int temp=0;
		int returnbegin=0;
		bool noget = true;
		for(int i=0;i<(*it).second.size();i++)
		{
			/*return key*/
			if((*it).second[i]>0)
			{
				noget=false;
				temp=i;
				//cout<<"debug 交界处的index "<<temp<<endl; 
				break;
			}
			else{
				/*cout<<"归还钥匙的空位 起始检索 "<<returnbegin<<endl;
				for(int j=0;j<n;j++)
				{
					cout<<j<<" ";
				}
				cout<<endl;
				for(int j=0;j<n;j++)
				{
					cout<<key[j]<<' ';
				} 
				cout<<endl;
				*/
				
				for(int j=returnbegin;j<n;j++)
				{
					if(key[j]==0)
					{
						
						key[j]=-(*it).second[i];
						id_index[ key[j] ] = j;
						
						returnbegin=j+1;
						//cout<<"have find empty index:"<<j<<' '<<"即将存放id:"<<key[j]<<endl;
						break;
					}
				}
			}
		}
		
		if(!noget)
		{
			for(int i=temp;i<(*it).second.size();i++)
			{
				/*get key*/
				//cout<<"需要的钥匙id:"<<(*it).second[i]
				///<<" 钥匙的所在index:"<<id_index[ (*it).second[i] ]<<endl;
				key[id_index[ (*it).second[i] ] ]=0; /*have gotten so box from full to empty*/
			}			
		}

	}
	for(int i=0;i<n;i++)
	{
		cout<<key[i]<<' ';
	}
	
	return 0;
} 
