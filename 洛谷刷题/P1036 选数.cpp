#include<iostream>
using namespace std;
bool issushu(int c){
	for(int i=2;i*i<=c;i++){
		if(c%i==0){
			return false;
		}
	}
	return true;
} 
int count[50];
int ans=0;
void dp(int index,int n,int sum,const int size){
	/*cout<<"int index,int n,int sum,const int size"<<index<<" "<<
		n<<" "<<sum<<' '<<size<<endl;*/
	if(n==0){
		if(issushu(sum))
		{
			ans++;
		}
		return ;
	}
	if(index>=size) return ;
	dp(index+1,n-1,sum+count[index],size);
		
	dp(index+1,n,sum,size);		
	
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>count[i];
	}
	dp(0,k,0,n);
	cout<<ans;
	return 0;
} 
