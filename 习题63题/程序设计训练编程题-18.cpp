#include<iostream>
#include<map>
#include<sstream>
using namespace std;
stringstream ss;
map<int,int>OneNumber;
map<int,int>::iterator mit;
pair<map<int,int>::iterator,bool>InsertJudge;

int TenToTwo(int Ten)
{
	 int count=0;
	 for(int i=1;i<=8;i++)
	 {
	 	if((Ten&1)) count++;
	 	
	 	Ten=Ten>>1;
	 }
	 return count;
}
int stringtoint(string &a)
{
	int result;
	ss<<a;
	ss>>result;
	ss.clear();
	ss.str("");
	return result;
}
int main()
{  
	
	for(int i=0;i<=255;i++)
	{	/*create table*/
		OneNumber.insert(make_pair(i,TenToTwo(i) )); 
	}
	/*cout<<endl;
	for(int i=0;i<=255;i++)
	{
		cout<<"i "<<i<<"OneNumber "<<OneNumber[i]<<endl;
	}*/
	int group;
	cin>>group;
	getchar();
	
	for(int g=0;g<group;g++)
	{
		string ip;
		cin>>ip;
		ip.push_back('.');
		int pos=0;
		string sub;
		int sum=0;
		/*cout<<"ip "<<ip<<endl;
		for(int i=0;i<ip.size();i++)
		{
			cout<<"i "<<i<<" " <<ip[i]<<" ";
		}
		cout<<ip[0]<<"6666"<<endl;
		cout<<ip[ip.size()-1]<<"6666";*/
		for(int i=0;i<ip.size();i++)
		{
			//cout<<"pos "<<pos<<" i "<<i<<endl;
			if(ip[i]=='.')
			{
				sub=ip.substr(pos,i-pos);
				//cout<<"i "<<i<<" "<<sub<<endl;
				//stringtoint(sub);
				sum+=OneNumber[stringtoint(sub)];
				pos=i+1;
			}
		}
		if(g==group-1)
		cout<<sum;
		else cout<<sum<<endl;
	}
	return 0;
} 

