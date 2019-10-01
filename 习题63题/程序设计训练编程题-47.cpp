#include<iostream>
#include<cstring>
#include<map>
#include<sstream>
using namespace std;
stringstream ss;
void stringtoint(string&str,int &result)
{
	ss<<str;
	ss>>result;
	ss.clear();
	ss.str("");
}
int main()
{
	string month[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen",
	"yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
	string Tzolkin[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat",
	"muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};	
	
	int mon[20];
	int monsumday[20];
	map<string,int>month_index;
	map<string,int>::iterator it; 
	int sum=0;
	for(int i=0;i<19;i++)
	{
		month_index.insert(make_pair(month[i],i+1));
		if(i+1<=18)
		{
			sum+=20;
			mon[i+1]=20;
		}else{
			sum+=5;
			mon[i+1]=5;
		} 
		monsumday[i+1]=sum;/*monsumday[i]是指过了第i个月后 
		即到达第i+1个月第一天是前i个月 经历的天数*/
	}
	int n;
	cin>>n;
	string dayandmonth,day,Month;
	int year;
	for(int i=0;i<n;i++)
	{
		cin>>dayandmonth>>year;
		day=dayandmonth.substr(0, dayandmonth.find('.') );
		Month=dayandmonth.substr(dayandmonth.find('.')+1,
		dayandmonth.size()-dayandmonth.find('.')-1);
		int d,m;
		stringtoint(day,d);
		m=month_index[Month];
		int numofday=year*365+monsumday[m-1]+d+1;
		
		int Tzolkinyear=numofday/260;
		numofday%=260;
		//cout<<"numofday "<<numofday<<endl;
		int monthyushu=numofday%20;
		if(monthyushu==0) monthyushu=20;
		/*1 2 3 4 5 6 .....19 0*/
		int dayyushu=numofday%13;
		
		if(dayyushu==0) dayyushu=13;
		cout<<dayyushu<<" "<<Tzolkin[monthyushu-1]<<" "<<Tzolkinyear<<endl;
		/*1 2 3 4 5 6 .....12 0*/
		
		//cout<<day<<" "<<Month<<" "<<year<<endl;
	}
	/*for(it=month_day.begin();it!=month_day.end();it++)
	{
		cout<<it->first<<' '<<it->second<<endl;
	}
	for(int i=1;i<=19;i++)
	{
		cout<<"mon[i] "<<mon[i]<<endl
			<<"monsumday[i] "<<monsumday[i]<<endl;
	}*/
	return 0;
}
