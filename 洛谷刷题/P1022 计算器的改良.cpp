#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;
stringstream ss;
void todouble(string sub,double&result){
	ss<<sub;
	ss>>result;
	ss.clear();
	ss.str("");
}
bool iscount(const char&ch ){
	if('0'<=ch&&ch<='9'){
		return true;
	}else return false;
}
bool isoperation(const char&ch){
	if(ch=='+'||ch=='-'){
		return 1;
	}else return false;
}

int main()
{
	string str;
	cin>>str;
	bool isleft=true;
	double xishu=0/*= de left*/,result=0/*= de right*/;
	
	if(!isoperation(str[0])){
		str.insert(0,"+");
	}
	
	for(int i=0;i<str.size();i++){
		if(str[i]=='='){
			isleft=false;
			continue;
		}
		
		if(isleft){
			if(isoperation(str[i])){
				double temp;
				todouble(str.substr(i,2),temp);
				if(!iscount(str[i+2])&&!isoperation(str[i+2])){
					xishu+=temp;
				}else{
					result+=-temp;
				}
			}		
		}else{
			
			if(isoperation(str[i])){
				double temp;
				todouble(str.substr(i,2),temp);
				if(i+2>=str.size()){
					result+=temp;
					continue;
				}
				
				if(!iscount(str[i+2])&&!isoperation(str[i+2])){
					xishu+=-temp;
				}else{
					result+=temp;
				}
			}			
		}
		
	}
	cout<<result<<' '<<xishu;
	//double ans=result/xishu;
	//cout<<ans;
	return 0;
} 
