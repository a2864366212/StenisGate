#include <iostream>
#include <vector>
using namespace std;
int main()
{
			string s;
	        vector<int> a;
	        char c;cin>>s;
	        for(int i=0;i<s.size();i++){
	            c=s[i];
	            //将加减乘除转换成数字
	            if(c=='+'){
	                a.push_back(10001);
	            }else if(c=='-'){
	                a.push_back(10002);
	            }else if(c=='x'){
	                a.push_back(10003);
	            }else if(c=='/'){
	                a.push_back(10004);
	            }else{
	                a.push_back(c-'0');
	            }
	        }
	        //遍历两次，第一次处理乘除，第二次处理加减
	        for(vector<int>::iterator it=a.begin();it!=a.end();){
	            if(*it==10003){
	                *(it-1)=*(it-1)*(*(it+1));
	                
	                it=a.erase(it);
	                it=a.erase(it);
	                continue;
	            }else if(*it==10004){
	                *(it-1)=*(it-1)/(*(it+1));
	                it=a.erase(it);
	                it=a.erase(it);
	                continue;
	            }
	            it++;
	        }
	        cout<<"处理乘除:\n"; 
	         for(vector<int>::iterator it=a.begin();it!=a.end();it++){
	         	cout<< *it<<' ';
	         }
	         cout<<endl;
	         /*9+3+4x3*/
	        for(vector<int>::iterator it=a.begin();it!=a.end();){
	            if(*it==10001){
	                *(it-1)=*(it-1)+(*(it+1));
	                it=a.erase(it);
	                it=a.erase(it);
	                continue;
	            }else if(*it==10002){
	                *(it-1)=*(it-1)-(*(it+1));
	                it=a.erase(it);
	                it=a.erase(it);
	                continue;
	            }
	            it++;
	        }
	        
	        cout<<"处理+-:\n"; 			 
	        cout<<*(a.end()-1)<<endl;
    return 0;
}

