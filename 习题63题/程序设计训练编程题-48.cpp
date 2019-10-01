#include<iostream>
#include<cstring>
#include<vector>
#include<sstream>
using namespace std;
stringstream ss;
void stringtoint(string&a,long long int&result)
{
	ss<<a;
	ss>>result;
	ss.clear();
	ss.str("");
}
int quick(int b)
{
	long long int a=10;
	
    long long int s = 1;
    while (b > 0) {
        if (b % 2 == 1) {//b=b>>1保证了在最后一步肯定会执行该if判断
            s = s * a;
        }
        a = a * a;
        b = b >> 1;
    }
    return s;
}
bool ans(string&count,vector<long long int>&mici,vector<int>&wenhaopos,
int i,long long int sum,long long int judge)
{
	/*for(int i=0;i<mici.size();i++)
	{
		cout<<"666666666 "<<mici[i]<<' ';
	}
	cout<<endl;
	*/if(i==mici.size())
	{
		//cout<<"sum "<<sum<<" judge "<<judge<<endl;
		if(sum>judge)
		return true;
	}
	else{
		for(int j=0;j<=9;j++){
			count[ wenhaopos[i] ]=j+'0';
			/*cout<<"cengshu i "<<i<<" meiju j "<<j<<endl
				<<"wenhaopos[i] "<<wenhaopos[i]<<endl
				<<"count[ wenhaopos[i] ] "<<count[ wenhaopos[i] ]<<endl
				<<"sum "<<sum<<endl;
			*/if( ans(count,mici,wenhaopos,i+1,sum+mici[i]*j,judge) ){
				return true;
			} 
		}  	
	}                                                                                                                                                                                                                                                                                               			
	return false;
}
int main()
{
	vector<long long int>mici;
	vector<int>wenhaopos;
	vector<int>::iterator it;
	string count;
	long long int mid;
	while(cin>>count)
	{
		long long int judge;
		cin>>judge;
		mid=0;
		for(int i=0;i<count.size();i++)
		{
			if(count[i]!='?')
			{//012345    0+c.size()-1==pos+x 
				mid+=(count[i]-'0')*quick( count.size()-1-i );
			}else{
				mici.push_back(quick(count.size()-i-1));
				wenhaopos.push_back(i);
			}	
		}
		//cout<<"judge "<<judge<<" mid "<<mid<<endl;
		if(!ans(count,mici,wenhaopos,0,0,judge-mid))
		{
			cout<<0<<endl;
		}else{
			
			long long int sum=0,max;
			string s,m;
			for(int i=0;i<mici.size();i++)
			{
				s+=count[ wenhaopos[i] ];
				m+='9';
			}
			
			stringtoint(s,sum);
			stringtoint(m,max);
			cout<< max-sum+1<<endl;
		}
		mici.erase(mici.begin(),mici.end());
		wenhaopos.erase(wenhaopos.begin(),wenhaopos.end());
	}
	return 0;
} 
