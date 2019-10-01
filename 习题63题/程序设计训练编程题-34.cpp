#include<iostream>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
stringstream ss;
vector<double>effect;
void stringtodouble(string &dou,double &result)
{

	ss<<dou;
	ss>>result;
	ss.clear();
	ss.str("");
}
double dp(double maxmoney)
{
	double max=0;
	int s=effect.size();
	unsigned long long int c=1;
	for(int i=1;i<=s;i++)
	{
		c*=2;
	}
	c-=1;
	unsigned long long int temp;
	double sum;
	for(unsigned int i=0;i<=c;i++)
	{
		temp=i;
		sum=0;
		for(int j=0;j<s;j++)
		{
			sum+=effect[j]*(temp&1);
			temp=temp>>1;
		}
		if(sum>maxmoney) continue;
		
		if(max<sum) max=sum;
	}
	return max;	
}
int main()
{
	while(1)
	{
		double edu;
		int zhang;
		cin>>edu>>zhang;
		if(zhang==0)
		{
			break;
		}
		for(int z=0;z<zhang;z++)
		{
			int xiang;
			cin>>xiang;
			string project,sub;/*�ж�ĳһ���Ƿ�Ϊ��Ч��Ʊ*/
			double sum=0;/*ĳ�� �� �������ܺ�*/
			
			bool IsEffective=true;
			for(int x=0;x<xiang;x++)
			{
				cin>>project;
				if(project[0]=='A'||project[0]=='B'||project[0]=='C')
				{
				}
				else {
					IsEffective=false;
					break;
				}
				
				sub=project.substr(2,project.size()-2);
				//cout<<sub<<endl;
				double OneMoney;/*������*/
				stringtodouble(sub,OneMoney);
				if(OneMoney>600)
				{
					IsEffective=false;
					break;
				}else{
					sum+=OneMoney;
				}
			}
			if(sum>1000)  IsEffective=false;
			
			if(IsEffective)
			{
				effect.push_back(sum);
			}
			
			/*for(int i=0;i<effect.size();i++)
			{
				cout<<"i "<<i<<" effect[i] "<<effect[i]<<endl;
			}*/
			//effect.erase(effect.begin(),effect.end());
		}
		double ans=dp(edu);
		printf("%.2lf\n",ans); 
		effect.erase(effect.begin(),effect.end());
	}
	return 0;
} 
