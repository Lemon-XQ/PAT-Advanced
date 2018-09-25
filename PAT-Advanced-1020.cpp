#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

void bfs(node* root){
	queue<node*> q;
	q.push(root);
	bool flag=false;
	while(!q.empty()){
		if(flag) cout<<" ";
		flag=true;
		node* n=q.front();
		cout<<n->data;
		q.pop();
		if(n->lchild!=NULL) q.push(n->lchild);
		if(n->rchild!=NULL) q.push(n->rchild);
	}
}

int post[100],in[100];
node* create(int postL,int postR,int inL,int inR){
	if(postL>postR) return NULL;// 后序序列为空
	node* root=new node;
	root->data=post[postR];
	int i;
	for(i=inL;i<=inR;i++){
		if(in[i]==post[postR]) break;// 找到中序中的根节点
	}
	int len_left=i-inL;// 左子树长度
	root->lchild = create(postL,postL+len_left-1,inL,i-1);// 注意边界
	root->rchild = create(postL+len_left,postR-1,i+1,inR);
//	root->lchild = create(postL+1,postL+len_left,inL,i-1);
//	root->rchild = create(postL+len_left+1,postR,i+1,inR);
	return root;
}

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++) cin>>post[i];
	for(int i=0;i<N;i++) cin>>in[i];
	node* root=create(0,N-1,0,N-1);// 重建树
	bfs(root);//　层序遍历
	return 0;
}





