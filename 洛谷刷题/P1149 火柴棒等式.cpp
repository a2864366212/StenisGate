//P1149 »ğ²ñ°ôµÈÊ½
#include<iostream>
#include<map>
using namespace std;
map<int,int>barnum_waynum;
map<int,int>::iterator it;
pair<map<int,int>::iterator,bool>insertjudge;
int main(){
	int a[1000]={6,2,5,5,4,5,6,3,7,6};
	int n;
	cin>>n;
	int temp;
	int sum=0;
	for(int i=10;i<1000;i++){
		temp=i;
		sum=0;
		while(temp!=0){
			sum+=a[(temp%10)];
			temp/=10;
		}
		a[i]=sum;
	}
	int ans=0;
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			if(i+j<1000){
				if(  a[i]+a[j]+4+a[i+j]==n  )
				{
					ans++;
				}				
			}
		}
	} 
	cout<<ans;
	return 0;
}
