#include<iostream>
using namespace std;
/*
R2，R3。六种命令的含义如下：
命令 A：将内存 M1 的数据装到寄存器 R1 中；
命令 B：将内存 M2 的数据装到寄存器 R2 中；
命令 C：将寄存器 R3 的数据装到内存 M1 中；
命令 D：将寄存器 R3 的数据装到内存 M2 中；
命令 E：将寄存器 R1 中的数据和寄存器 R2 中的数据相加，结果放到寄存器 R3 中；
命令 F：将寄存器 R1 中的数据和寄存器 R2 中的数据相减，结果放到寄存器 R3 中。*/
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
