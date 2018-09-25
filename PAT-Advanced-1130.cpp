#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

struct node{
	string data;
	node* lchild;
	node* rchild;
};

vector<string> ans;
void inOrder(node* root){
	if(root==NULL) return;
	if(root->lchild!=NULL || root->rchild!=NULL) ans.push_back("(");
	inOrder(root->lchild);
	ans.push_back(root->data);
	inOrder(root->rchild);
	if(root->rchild!=NULL) ans.push_back(")");
}

int main(){
	int N;
	cin>>N;
	node* arr=new node[N+1];
	bool visit[21]={false};
	for(int i=1;i<=N;i++){
        string a,b,c;
        cin>>a>>b>>c;
		if(b!="-1") visit[atoi(b.c_str())]=true;
		if(c!="-1") visit[atoi(c.c_str())]=true;
        arr[i].lchild=(b=="-1")?NULL:&arr[atoi(b.c_str())];
        arr[i].rchild=(c=="-1")?NULL:&arr[atoi(c.c_str())];
        arr[i].data=a;
	}
	int root;
	for(int i=1;i<=N;i++){
		if(visit[i]==false){
			root=i;
			break;
		}
	}
	node* n=&arr[root];
	inOrder(n);
	if(N==1) cout<<arr[1].data;
	else for(int i=1;i<ans.size()-1;i++) cout<<ans[i];
	return 0;
}
