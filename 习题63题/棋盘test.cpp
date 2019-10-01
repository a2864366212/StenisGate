#include<iostream>
using namespace std;
int chess[2500][2500];
void change(int &color)
{
	if(color==0) color=1;
	else color=0;
}
int main()
{
	int n;
	cin>>n;
	char ch;
	getchar();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ch=getchar();
			chess[i][j]=ch-'0';
		}
		getchar();
	}
	
	int size[n*n];
	int sizeindex=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int nowsize=0;
			if(chess[i][j]==0) 
			{
				size[sizeindex]=0;
			}else{
				//cout<<"group "<<"chess[][]"<<i<<' '<<j<<endl; 
				nowsize=1;
				int begincolor;
				bool finish=false;
				while(1)
				{
					if(nowsize%2!=0)
					{
						begincolor=0;
					}else{
						begincolor=1;
					}
					int temp=begincolor;
					for(int row=i;row<=i+nowsize;row++)
					{
						if(chess[row][j+nowsize]!=begincolor)
						{
							finish=true;
							break;
						}
						//cout<<begincolor<<endl;
						//cout<<"finish"<<finish<<endl;
						change(begincolor);							
					}
					//cout<<begincolor<<"mid from row to col"<<endl;
					//change(begincolor);
					begincolor=temp;
					for(int col=j;col<=j+nowsize;col++)
					{
						//cout<<"finish"<<finish<<endl;
						//cout<<"**chess i+nowsize "<<i+nowsize<<"col "<<col<<"beginc "<<begincolor<<endl;;
						if(chess[i+nowsize][col]!=begincolor)
						{
							
							finish=true;
							break;
						}
						//cout<<begincolor<<' ';
						change(begincolor);							
					}
					//cout<<endl;
					
					if(!finish)
					nowsize++;
					else break;
				}
				size[sizeindex]=nowsize;
			}/*else µÄ*/
			sizeindex++;
		}
	}
	int max=0;
	for(int i=0;i<n*n;i++){
		if(max<size[i]){
			max=size[i];
		}
	}
	int ans=0;
	for(int i=0;i<n*n;i++){
		if(max==size[i]){
			ans++;
		}
	}
	cout<<max<<' '<<ans;
	return 0;
}
