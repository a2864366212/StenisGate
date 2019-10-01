#include<iostream>
#define eps 0.00000001
using namespace std;
int main()
{
	double distance=7;
	/*0.98*/
	double s,x;
	cin>>s>>x;
	double away,temp;
	for(int t=1;;t++){	
		if(away>=s-x -eps){
			break;	
		}
		away+=distance;
		distance*=0.98;
	}
	/*
	7
	13 15*/
	if(s+x-away<distance-eps){
		/*dis-eps dis+eps*/
		cout<<'n';
		return 0; 
	}
	else{
		cout<<'y';
		return 0;
	}
	return 0;
}
