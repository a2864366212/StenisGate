#include<iostream>
#include<cstring>
#include<sstream>
#include<vector>
#include<cstdio>
using namespace std;
stringstream ss;
vector<string>L,R;
void stringtodouble(string str,double &res)
{
    ss<<str;
    ss>>res;
    ss.clear();
    ss.str("");
}
void todouble(string sub,double&result){
    ss<<sub;
    ss>>result;
    ss.clear();
    ss.str("");
}
bool iscount(char &ch){
    if('0'<=ch&&ch<='9')
    {
        return true;
    }else return false;
}
bool isletter(char &ch)
{
    if('a'<=ch&&ch<='z')
    {
        return true;
    }else{
        return false;
    }
}
bool isoperation(char&ch)
{
    if(ch=='-'||ch=='+') return true;
    else return false;
}

void modify(string&str)
{
    if(!isoperation(str[0])){
        str.insert(0,"+");
    }
}
void solve(vector<string>&ans,string&str)
{
    for(int i=0;i<str.size();i++)
    {
        int temp;
        if( isoperation(str[i]) )
        {
            temp=i;
            i++;
            if(i>=str.size()) break;
            while(1)
            {
                if( isoperation(str[i]) )
                {
                    break;		
                }
                i++;
            }   
            ans.push_back(str.substr(temp,i-temp));
            //cout<<temp<<' '<<i<<endl;
            //cout<<ans[ans.size()-1]<<endl;
            i--;
        }
    }
}
void solution(bool isleft,vector<string>ans,double &result,double &xishu,char& weizhishu)
{
    int repair=isleft?1:-1;
    for(int i=0;i<ans.size();i++)
    {
        if(isletter(ans[i][ans[i].size()-1]))
        {
            //cout<<"is weizhishu xishu: ";
            if(ans[i].size()==2)
            {
                //cout<<ans[i][0]<<1;
                weizhishu= ans[i][1];
                xishu+=repair;
            }else{
                double temp;
                //cout<<ans[i].substr(0,ans[i].size()-1 );
                stringtodouble( ans[i].substr(0,ans[i].size()-1 ),temp);
                weizhishu=ans[i][ans[i].size()-1];
                xishu+=repair*temp;
            }
            //cout<<" weizhishu "<<ans[i][ans[i].size()-1];
        }else{
            //cout<<"shuzi count "<<ans[i];
            double temp;
            stringtodouble(ans[i],temp);
            result+= (-repair)*temp;
        }
    }
}

int main()
{
    string str;
    char weizhishu;
    cin>>str;
    int pos=str.find('=');
    string left=str.substr(0,pos),right=str.substr(pos+1,str.size()-(pos+1) );
    //cout<<left<<' '<<right<<endl;
    modify(left);
    modify(right);
    
    ///cout<<left<<' '<<right<<endl;
    left+='+';
    right+='+';
    //cout<<left<<' '<<right<<endl;
    
    solve(L,left);
    solve(R,right);
    
    /*for(int i=0;i<L.size();i++)
    {
        cout<<L[i]<<endl;
    }
    for(int i=0;i<R.size();i++)
    {
        cout<<R[i]<<endl;
    }	*/
    double result=0,xishu=0;
    solution(1,L,result,xishu,weizhishu);
    solution(0,R,result,xishu,weizhishu);
    //cout<<result/xishu;
    result=result/xishu;;
    printf("%c=%.3lf",weizhishu,result);
    return 0;
}
