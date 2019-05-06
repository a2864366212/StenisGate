#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	cout<<"number of object"<<endl;
	cin>>n;
	int capacity;
	cout<<"capacity of bag"<<endl;
	cin>>capacity;
	int v[n],w[n];
	for(int i=0;i<n;i++)
	{
		cout<<"value"<<endl;
		cin>>v[i];
		cout<<"weight"<<endl;
		cin>>w[i];
	}
	cout<<"weight"<<"\t"<<"value"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"   "<<w[i]<<"  "<<"\t"<<"   "
		<<v[i]<<endl;
	}
	int result[capacity];
	for(int i=0;i<=capacity;i++)
	{
		if(w[0]<=i)
		{
			result[i]=v[0];
		}
		else
		{
			result[i]=0;
		}
	}/*初始化opt[0][0~capacity] 解空间树的最后一层
		能放就放 不能即为 0*/

	cout<<0<<"--";
	for(int c=capacity;c>=0;c--)
	{
		cout<<setw(2)<<left<<result[c]<<" ";
	}
	cout<<endl;
	for(int i=1;i<n;i++)
	{
		cout<<i<<"--";
		for(int c=capacity;c>=0;c--)
		{
			if(c>=w[i])
			result[c]
			=max(v[i]+result[c-w[i]],result[c]);
			cout<<setw(2)<<left<<result[c]<<" ";
		} 
		cout<<endl;
	}
	cout<<result[capacity];
	return 0;
}
