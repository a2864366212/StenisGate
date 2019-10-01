#include<iostream>
#include<sstream>
#include<string>
using namespace std;
stringstream ss;
void tostring(int c,string&result){
	ss<<c;
	ss>>result;
	ss.clear();
	ss.str("");
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int A=0,B=0,C=0;
	string aa,bb,cc,result;
	int needno=true;
	
	while(1){
		A+=a;
		B+=b;
		C+=c;
		if(A>=100&&B>=100&&C>=100){
			int flag[10]={0};
			tostring(A,aa);
			tostring(B,bb);
			tostring(C,cc);
			result+=aa+bb+cc;
			for(int i=0;i<result.size();i++){
				flag[result[i]-'0']++;
			}
			int symbol=0; 
			for(int i=1;i<=9;i++){
				if(flag[i]==1){
					symbol++;
				}
			}
			if(symbol==9){
				cout<<A<<' '<<B<<' '<<C<<endl;
				needno=false;
			}
		}
		if(A>999||B>999||C>999){
			break;
		}
		result="";
	}
	if(needno){
		cout<<"No!!!";
	}
	return 0;
}
