#include<iostream>
using namespace std;
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isryear(int year)
{
	if( (year%400==0)||
	(year%4==0&&year%100!=0) ){
		return true;
	}else{
		return false;
	}
}
int main()
{
	int year=0,num=0;
	cin>>year>>num;
	if(isryear(year)){
		d[2]=29;
	}
	
	//num
	int month=1,day=0;
	for(int i=1;i<=12;i++)
	{
		if(num>d[i]){
			num-=d[i];
		}else{
			month=i;
			break;
		}
	}
	day=num;
	cout<<month<<endl<<day;
	return 0;
} 
