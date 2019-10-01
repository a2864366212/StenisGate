#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;
string ans[20000];
stringstream ss;
bool issushu(int c){
	if(c==1) return false;
	for(int i=2;i*i<=c;i++){
		if(c%i==0){
			return false;
		}
	}
	return true;
}
void tostring(int c,string&result){
	ss<<c;
	ss>>result;
	ss.clear();
	ss.str("");
}
int main()
{
	for(int i=0;i<20000;i++){
		ans[i]="";
	}
	string a,b,c,result;
	for(int i=2;i<20000-2;i++){
		for(int j=i+1;j<20000-1;j++){
			for(int k=j+1;k<20000;k++){
				if (issushu(i)&&
					issushu(j)&&
					issushu(k)&&i+j+k<20000){
						/*tostring(i,a);
						tostring(j,b);
						tostring(k,c);
						ans[i+j+k]+=a+" "+b+" "+c+" ";*/
						cout<<i<<' '<<j<<' '<<k<<endl;
					}
			}
		}
	}
	for(int i=0;i<20000;i++){
		if(ans[i]!=""){
			cout<<i<<' '<<ans[i]<<endl;
		}
	}
}
