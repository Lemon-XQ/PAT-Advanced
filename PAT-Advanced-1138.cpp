#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

const int MAXV=50001;
const int INF=0x3fffffff;

struct node{
	node* lchild;
	node* rchild;
	int data;
};

int pre[MAXV],in[MAXV];
node* create(int preL,int preR,int inL,int inR){
	if(preL>preR) return NULL;
	node* root=new node;
	root->data=pre[preL];
	int i;
	for(i=inL;i<=inR;i++){
		if(in[i]==pre[preL]) break;
	}
	int len=i-inL;
	root->lchild=create(preL+1,preL+len,inL,i-1);
	root->rchild=create(preL+len+1,preR,i+1,inR);
	return root;
}

vector<int> ans;
void postOrder(node* root){
	if(root==NULL) return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	ans.push_back(root->data);
}

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++) cin>>pre[i];
	for(int i=0;i<N;i++) cin>>in[i];
	node* root=create(0,N-1,0,N-1);
	postOrder(root);
	cout<<ans[0]<<endl;
	return 0;
}
