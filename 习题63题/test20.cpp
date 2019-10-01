#include<iostream>
#include<sstream> 
using namespace std;
/*9num 9  =2
num 2= 99 =(3|8)*(0~9)+(!3&!8)    *  [~(0~9)~]
	         2  * 10^1  [0,1,2..9] *  num 9
999=(3|8)*(0~99)
	  2  *  10^2 [0,1,2..9] *  num99 */
stringstream ss;
void stringtollint(string & s, int& result)
{
	ss<<s;
	ss>>result;
	ss.clear();
	ss.str("");
}	  
 int num[15]={0};
 int TenMicifang[15]={0};
int main()
{
	int group;
	cin>>group;
	
	num[1]=2;
	
	TenMicifang[0]=1;
	TenMicifang[1]=10;
	for(int i=2;i<=11;i++)
	{
		num[i]= 2*TenMicifang[i-1] + 8*num[i-1];
		//cout<<"i "<<i<<", num[i] "<<num[i]<<endl;
		TenMicifang[i]=10*TenMicifang[i-1];
	}

	for(int g=0;g<group;g++)
	{		
		string str;
		cin>>str;	
		//answer(str,num,TenMicifang);

	 int sum=0;
	for(int index=0;index<str.size();index++)
	{
		 int count;
		bool NeedFinish=false;
		while(1)
		{
			count=str[index]-'0'-1;
			
			if(count>=0) break;
			index++;
			if(index>=str.size())	NeedFinish=true;	
		}
		if(NeedFinish) break;
		
		if(count<=1) //!3!8
		{/*0 01 */
			/*cout<<*/  sum+= (count+1)*num[str.size()-index-1];
		}else{/*0 1 2   4 5 6 7   9 */
		      /*- 0 1   3 4 5 6   8 */ 
			if(count<=6)
			{/*0 1 2  3  4 5 6 */
				/*cout<<*/sum+= (count/*count-3*/)*num[str.size()-index-1]+ TenMicifang[str.size()-index-1];
			
			}else{//0 1 2 3 4 5 6 7 8  count only equals to 8
				/*cout<< */sum+= 7*num[str.size()-index-1]+ 2*TenMicifang[str.size()-index-1];				
			}
		}		
	} 
	int result;
	stringtollint(str,result);
	cout<<oct<<result-sum<<endl;	
	}
	
	return 0;
}
