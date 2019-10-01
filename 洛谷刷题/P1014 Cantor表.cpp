#include<iostream>
using namespace std;
void answer(long long int N){
	int n;
	for(int i=1;;i++){
		if( ((i+1)*i)/2 >= N ){
			n=i;		
			break;
		} 
	}
	int pos = N-( (n-1)*n/2 );
	if(n%2==0){
		cout<<pos<<'/'<<n+1-pos;
	} else{
		cout<<n-pos+1<<'/'<<pos;
	}	
}
int main()
{
	long long int N;
	cin>>N;
	answer(N);
} 
