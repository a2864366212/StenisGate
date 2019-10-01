#include<iostream>
using namespace std;

int ans[21][21][21];/*0~20 index*/
int fill(int a,int b,int c)
{
	if(a<=0||b<=0||c<=0){
		return 1;
	}
	if(a>20||b>20||c>20){
		if(ans[20][20][20]==-5)
		{
			 ans[20][20][20]=fill(20,20,20);
		}
		return ans[20][20][20];
	}
	if(a<b&&b<c){
		if(ans[a][b][c-1]==-5) ans[a][b][c-1]=fill(a,b,c-1);/*1 2 2*/
		if(ans[a][b-1][c-1]==-5) ans[a][b-1][c-1]=fill(a,b-1,c-1);/*1 1 2*/
		if(ans[a][b-1][c]==-5) ans[a][b-1][c]=fill(a,b-1,c);/*1 1 3*/
		
//		cout<<"6666666 "<<ans[a][b][c-1]<<' '<<
//		ans[a][b-1][c-1]<<' '<<ans[a][b-1][c]<<endl;
		
		return ans[a][b][c-1]+
		ans[a][b-1][c-1]-ans[a][b-1][c];
	}
	//cout<<" a b c 4 "<<a<<' '<<b<<' '<<c<<endl;
	if(ans[a-1][b][c]==-5) ans[a-1][b][c]=fill(a-1,b,c);
//	cout<<"ans[a-1][b][c] "<<ans[a-1][b][c]<<endl;
	if(ans[a-1][b-1][c]==-5) ans[a-1][b-1][c]=fill(a-1,b-1,c);
//	cout<<"ans[a-1][b-1][c] "<<ans[a-1][b-1][c]<<endl;
	if(ans[a-1][b][c-1]==-5) ans[a-1][b][c-1]=fill(a-1,b,c-1);
//	cout<<"ans[a-1][b][c-1] "<<ans[a-1][b][c-1]<<endl;
	if(ans[a-1][b-1][c-1]==-5) ans[a-1][b-1][c-1]=fill(a-1,b-1,c-1);
//	cout<<"ans[a-1][b-1][c-1] "<<ans[a-1][b-1][c-1]<<endl;	
	return ans[a-1][b][c]+ans[a-1][b-1][c]+
	ans[a-1][b][c-1]-ans[a-1][b-1][c-1];
}
int main()
{	
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			for(int k=0;k<21;k++){
				ans[i][j][k]=-5;
			}
		}
	}
	
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			ans[0][i][j]=1;
		}
	}
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			ans[i][0][j]=1;
		}
	}
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			ans[i][j][0]=1;
		}
	}
 	while(1)
 	{
 		long long int a,b,c;
 		cin>>a>>b>>c;
 		
 		if(a==-1&&b==-1&&c==-1){
 			break;
 		}
		 cout<<"w("<<a<<", "<<b<<", "<<c<<") = ";
		if(a<=0||b<=0||c<=0){
			cout<<1<<endl;
			continue;
		}
 		if(a>20||b>20||c>20){
 			cout<<fill(21,21,21)<<endl;
 			continue;
 		}
 		int aa=a,bb=b,cc=c;
 		cout<<fill(aa,bb,cc)<<endl;
 	}
	return 0;
}
