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
	int
	 
}
