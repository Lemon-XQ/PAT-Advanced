#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV=31;

int N,pre[MAXV],post[MAXV];

struct node{
	int data;
	node* lchild;
	node* rchild;
};

vector<int> ans;
bool first=true;
void inOrder(node* root){
	if(root==NULL) return;
	inOrder(root->lchild);
	if(!first) cout<<" ";
	cout<<root->data;
	first=false;
	inOrder(root->rchild);
}

node* create(int preL,int preR,int postL,int postR){
	if(preL>preR){
		return NULL;
	}else if(preL==preR){
		node* n=new node;
		n->data=pre[preL];
		n->lchild=n->rchild=NULL;
		return n;
	}
	node* root=new node;
	root->data=pre[preL];
	int i;
	for(i=postL;i<=postR;i++){
		if(post[i]==pre[preL+1]) break;
	}
	int left=i-postL;
	root->lchild=create(preL+1,preL+left+1,postL,i);
	root->rchild=create(preL+left+2,preR,i+1,postR-1);
	return root;
}

int main(){
	cin>>N;
	int index=-1;
	for(int i=0;i<N;i++) cin>>pre[i];
	for(int i=0;i<N;i++){
		cin>>post[i];
		if(N!=1 && post[i]==pre[1]) index=i;
	}
	if(N==1){
		cout<<"Yes"<<endl<<pre[0]<<endl;
		return 0;
	}
	// 思路：找先序序列第二个在后序序列中的位置，该位置左边和右边的个数都需为偶数才能保证树唯一
	// eg.1234 2431
	if(index%2==0 && (N-1-index)%2==0){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	node* root=create(0,N-1,0,N-1);
	inOrder(root);
	cout<<endl;
	return 0;
}
