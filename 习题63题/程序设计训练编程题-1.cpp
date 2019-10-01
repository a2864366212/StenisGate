#include<iostream>
#include<cstring>
using namespace std;
class node
{
    public:
    char val;
    node *left=NULL;
    node *right=NULL;
    public:
        node(){
        }
        node(node *parent,bool IsLeftSon,char val){
            this->val=val;
            if(parent!=NULL)
            {
                if(IsLeftSon)
                {
                    (*parent).left=this;
                }else{
                    (*parent).right=this;
                }
            }
        }
};
node * root;
void build_tree(const string &before,const string &mid,node *parent,bool IsLeftSon)
{
    if(before.length()==0)
    {
        return ;
    }
    /*cout<<"IsLeftSon "<<IsLeftSon<<" before "<<before<<" mid "<<mid<<endl;
    if(parent)
    cout<<parent->val<<endl;
    else{
        cout<<"o error"<<endl;
    }*/
    node *p=new node (parent,IsLeftSon,before[0]);
    /*if(parent==NULL)
    {
        root=p;
      	cout<<"**************************"<<endl; 
      	cout<<"root "<<root<<" root->val "<<root->val<<" before[0] "<<before[0]<<endl
      		<<"    a.val "<<(*p).val<<endl;
 	    cout<<"**************************"<<endl; 
    }*/
    if(parent==NULL)
    {root=p;}
    
    int pos=mid.find(before[0]);
    build_tree(before.substr(1,pos),mid.substr(0,pos),p,true);/*left*/
    build_tree(before.substr(pos+1,before.size()-(pos+1)),
                      mid.substr(pos+1,mid.size()-(pos+1)),p,false);/*right*/
}
void afterPrint_tree(node *root)
{
    if(root==NULL)
    {
        return ;
    }else{

        afterPrint_tree(root->left);
        afterPrint_tree(root->right);
        cout<< root->val;
    }
    /*cout<<root<<endl;
    cout<<root->val<<endl;
	cout<<root->left<<endl;
	cout<<root->left->val<<endl;
	cout<<root->right;*/
}
int main()
{
    /*string before,mid;
    cin>>before>>mid;
    build_tree(before,mid,NULL,true);
    afterPrint_tree(root);*/
    int n;
    while(cin>>n)
    {
    	if(n==0) break;
	    string before,mid;
	    cin>>before>>mid;
	    build_tree(before,mid,NULL,true);
	    afterPrint_tree(root);	
		cout<<endl;		
    }
    return 0;
}

