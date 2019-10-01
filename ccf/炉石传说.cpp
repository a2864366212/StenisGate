#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
class soldier
{
	public:
	soldier(){
	}
	soldier(int a,int b){
		attack=a;
		health=b;
	}
	int attack;
	int health;
	
};
soldier myclear(0,0);
void DeathSort(vector<soldier>&a,int id){
		if(a.back().health>0){
			for(int i=id;i<=6;i++){
				a[i]=a[i+1];
			}
			a[7]=myclear;		
		}			
		else{
			for(int i=id;i<=6;i++){
				a[i]=a[i+1];
			}
			
		}
		/*7->6*/
		/*6->5*/		
}
void InsertSort(vector<soldier>&a,int id){
	for(int i=7;i>=id+1;i--){
		a[i]=a[i-1];	
	}
}
void test(vector<soldier>&a)
{
	vector<soldier>::iterator it;
	for(it=a.begin();it!=a.end();it++){
		cout<<(*it).health<<' '; 
	}
	cout<<endl;
}
int main()
{
	vector<soldier>before(8,soldier(0,0));
	vector<soldier>behind(8,soldier(0,0));
	int beforer_health=30,behinder_health=30;
	string a="summon",b="attack",c="end";
	int n;cin>>n;
	string choice;
	int id,attack,health;
	int id_attack,id_defend;
	for(int ii=1,i=1;ii<=n;ii++){
		cin>>choice;
		if((i+1)%2==0){/*beforer attempt to attack*/
			if(choice==a){
				cin>>id;
				InsertSort(before,id);
				cin>>before[id].attack>>before[id].health;
				
		//		test(before);
					
			}		
			if(choice==b){/*attempt to attack each other*/
				cin>>id_attack>>id_defend;
				if(id_defend==0){
					behinder_health-=before[id_attack].attack;
				}else{
					before[id_attack].health-=behind[id_defend].attack;
					behind[id_defend].health-=before[id_attack].attack;
					
					if(before[id_attack].health<=0){
						DeathSort(before,id_attack);
					}
					if(behind[id_defend].health<=0){
						DeathSort(behind,id_defend);
					}
					
					/*cout<<"before\n";
					test(before);
					cout<<"behind\n";
					test(behind);*/
					
				}
			}	
			
			if(choice==c) {
				i++;
				continue;
			}
			
		}else{
			if(choice==a){/*behinder attempt to attack*/
				cin>>id;
				InsertSort(behind,id);
				cin>>behind[id].attack>>behind[id].health;
			//	test(behind);
			}
			if(choice==b){
				cin>>id_attack>>id_defend;
				if(id_defend==0){
					beforer_health-=behind[id_attack].attack;
				}else{
					behind[id_attack].health-=before[id_defend].attack;
					before[id_defend].health-=behind[id_attack].attack;
					
					if(behind[id_attack].health<=0){
						DeathSort(behind,id_attack);
					}
					if(before[id_defend].health<=0){
						DeathSort(before,id_defend);
					}
					
				/*	cout<<"before\n";
					test(before);
					cout<<"behind\n";
					test(behind);*/
					
				}
								
			}
			if(choice==c) {
				i++;
				continue;
			}			
		}

	}
	
	if(beforer_health>0 && behinder_health>0){
		cout<<'0'<<endl;
	}else{
		if(beforer_health<=0) cout<<-1<<endl;
		if(behinder_health<=0) cout<<1<<endl;
	}
	
	cout<<beforer_health<<endl;
	
	vector<soldier>::iterator it;
	int survival_before=0,survival_behind=0;
	for(it=before.begin();it!=before.end();it++){
		if((*it).health>0) survival_before++;
	}
	cout<<survival_before;

	for(it=before.begin();it!=before.end();it++){
		health=(*it).health;
		 if(health>0) cout<<' '<<health;
	}
	cout<<endl;
	
	cout<<behinder_health<<endl;
	
	for(it=behind.begin();it!=behind.end();it++){
		if((*it).health>0) survival_behind++;
	}
	cout<<survival_behind;
	
	for(it=behind.begin();it!=behind.end();it++){
		health=(*it).health;
		 if(health>0) cout<<' '<<health;
	}
	return 0;
}
