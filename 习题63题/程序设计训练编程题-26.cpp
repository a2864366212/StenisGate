#include<iostream>
using namespace std;
/*
R2��R3����������ĺ������£�
���� A�����ڴ� M1 ������װ���Ĵ��� R1 �У�
���� B�����ڴ� M2 ������װ���Ĵ��� R2 �У�
���� C�����Ĵ��� R3 ������װ���ڴ� M1 �У�
���� D�����Ĵ��� R3 ������װ���ڴ� M2 �У�
���� E�����Ĵ��� R1 �е����ݺͼĴ��� R2 �е�������ӣ�����ŵ��Ĵ��� R3 �У�
���� F�����Ĵ��� R1 �е����ݺͼĴ��� R2 �е��������������ŵ��Ĵ��� R3 �С�*/
int main()
{
	bool NeedEnd=false;
	while(1)
	{
		long long int m1,m2,r1,r2,r3;
		cin>>m1>>m2;
		string demand;
		if(!(cin>>demand)){
			break;
		//	cout<<"asd "<<endl;as
		}
		for(int i=0;i<demand.size();i++)
		{
			switch(demand[i])
			{
				case 'A':r1=m1;break;
				case 'B':r2=m2;break;
				case 'C':m1=r3;break;
				case 'D':m2=r3;break;
				case 'E':r3=r1+r2;break;
				case 'F':r3=r1-r2;break;
				default:break;
			} 
		}
		cout<<m1<<','<<m2<<endl;
	}
	return 0;
} 
