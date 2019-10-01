#include<iostream>
#include<map>
using namespace std;
map<int,string>birth_id;
map<int,string>::iterator mit;
pair<map<int,string>::iterator,bool>InsertJudge;
void PrintBirth(int birth)
{
	cout<<birth/100<<" "<<birth%100<<' ';
}
int main()
{
	int n;
	cin>>n;
	string id;
	int month,day;
	for(int i=0;i<n;i++)
	{
		int birth=0;
		cin>>id>>month>>day;
		/*12 12
		5 12*/
		int tenMici=100;
		while(month!=0)
		{
			birth+= (month%10)*tenMici;
			month/=10;	
			tenMici*=10;
		}
		tenMici=1;
		while(day!=0)
		{
			birth+= (day%10)*tenMici;
			day/=10;	
			tenMici*=10;			
		}
		//cout<<birth<<endl;
		InsertJudge=birth_id.insert(make_pair(birth,id));
		if(InsertJudge.second==false)
		{
			birth_id[birth]+=' ';
			birth_id[birth]+=id;		
		}
	}
	
	for(mit=birth_id.begin();mit!=birth_id.end();mit++)
	{
		PrintBirth(mit->first);
		cout<<(mit->second)<<endl;
	}
	
	return 0;
}
 
