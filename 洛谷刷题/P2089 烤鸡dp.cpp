#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<string>ans;
char temp[10]; 
void deeptrack(int index,int n,int sum)
{/*end is the tenth ->index = 10*/
	if(sum>n){
		return ;
	}
	if(index==11&&sum!=n){
		return ;
	}
	if(index==11&&sum==n){
		string answer(temp);
		ans.push_back(answer);
		return ;
	}else{
		for(int i=1;i<=3;i++){
			temp[index-1] = i+'0';
			deeptrack(index+1,n,sum+i);
		}		
	}
}
int main()
{
	int n;
	cin>>n;
	deeptrack(1,n,0);
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++){
			if(j==0){
				cout<<ans[i][0];
			}else{
				cout<<' '<<ans[i][j];
			}	
		}
		cout<<endl;
	}
	return 0;
} 
