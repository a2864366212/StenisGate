#include<iostream>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
map<char,bool>needc;
map<char,bool>::iterator it;

map<string,string>solution;
map<string,string>::iterator sit;
pair<map<string,string>::iterator , bool>insertjudge;
bool isletter(char&ch)
{
	if('a'<=ch&&ch<='z')
	{
		return true;
	}
	else return false;
}
bool iscount(char&ch)
{
	if('0'<=ch&&ch<='9')
	{
		return 1;
	}else{
		return 0;
	}
}
bool ischoice(string & str,char&result)
{
	if(str.size()>2) return false;
	else{
		if(str[0]=='-'&&isletter(str[1]))
		{
			result=str[1];
			return true;
		}
		else return false;
	}
} 
/*Ð¡Ð´×ÖÄ¸,Êý×ÖºÍ¼õºÅ×é³ÉµÄ·Ç¿Õ×Ö·û´®¡£*/
bool isc(string&str)
{
	char ch;
	for(int i=0;i<str.size();i++)
	{
		ch=str[i];
		if( !isletter(ch)&&
			!iscount(ch)&&
			ch!='-'){
				return false;
			}
	}
	return true;
}
void solve(vector<string>&ans)
{
	string temp1,temp2;
	for(int i=0;i<ans.size();i++)
	{
		//cout<<"i "<<i<<endl; 
		char result;
		/*cout<<"ischoice(ans[i], result) "<<ischoice(ans[i], result)<<endl;
		cout<<"ans[i] "<<ans[i]<<endl;
		cout<<"result -right "<< result<<endl;  
		*/
		
		if(ischoice(ans[i], result) )
		{
			if(needc.find(result)!=needc.end()){
				temp1='-';
				temp1.push_back(result);
				//cout<<"needc[result] "<<needc[result]<<endl
				//	<<"result "<<result<<endl;
				if(needc[result]==1){
					
					/*need c*/
					if(i+1>=ans.size())
					{
						break;
					}else{
						if(isc(ans[i+1]))
						{
							insertjudge=solution.insert(make_pair(temp1,ans[i+1]) );
							if(!insertjudge.second)
							{
								solution[temp1]=ans[i+1];
							}
							i++;
						}else{
							break;
						}
					}
				}else{
					/*non c*/
					temp2=" ";
					//cout<<"temp1 *"<<temp1<<"temp2 *"<<temp2<<endl;
					solution.insert(make_pair(temp1,temp2) );
				}
				
			}else{
				break;
			}
		}else{
			break;	
		}
	}
	for(sit=solution.begin();sit!=solution.end();sit++)
	{
		if((*sit).second==" ")
		{
			cout<<' '<<(*sit).first;
		}else{
			cout<<' '<<(*sit).first<<' '<<(*sit).second;
		}
	}
	solution.erase(solution.begin(),solution.end());
}
int main() 
{
	string in;
	cin>>in;
	for(int i=0;i<in.size();i++)
	{
		if(i+1<in.size())
		{
			if(in[i+1]==':')
			{
				needc.insert(make_pair(in[i],1));
				//cout<<in[i]<<' '<<1<<endl;
				i++;
			}else{
				needc.insert(make_pair(in[i],0));
				//cout<<in[i]<<' '<<0<<endl;
			}
		}else{
			needc.insert(make_pair(in[i],0));
			//cout<<in[i]<<' '<<0<<endl;
		}
	}
	/*for(it=needc.begin();it!=needc.end();it++)
	{
		cout<<(*it).first<<' '<<(*it).second<<endl;
	}*/
	int n;
	cin>>n;
	getchar();
	string str;
	vector<string>ans;
	int kcase=1;
	for(int line=0;line<n;line++)
	{
		getline(cin,str);
		str.push_back(' ');
		//cout<<str<<'+'<<endl;
		int pos=0;
		for(int i=0;i<str.size();i++)
		{
			if(str[i]==' ')
			{
				pos=i;
				break;
			}
		}
		//cout<<pos<<'*'<<endl;
		str=str.substr(pos,str.size()-pos);

		int before=0,now=0;
		/*µ¥¶À²âÊÔ ls+0 ls+1 ls+2 */
		string temp;
		
		for(int i=1;i<str.size();i++)
		{
			if(str[i]==' ')
			{
				now=i;
				temp=str.substr(before+1,now-before-1); //now-(before+1)  
				before=now;
				//cout<<temp<<endl;
				ans.push_back(temp);
			}	
		}
		
		cout<<"Case "<<kcase<<':';
		solve(ans);
		kcase++;
		
		ans.erase(ans.begin(),ans.end());
		if(line!=n-1) cout<<endl;
	} 
	return 0;
}
