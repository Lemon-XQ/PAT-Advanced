#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	node* lchild;
	node* rchild;
	int data;
	int height;
};

int getBalanceFactor(node* root){
	int height_left=(root->lchild==NULL)?0:root->lchild->height;
	int height_right=(root->rchild==NULL)?0:root->rchild->height;
	return height_left-height_right;
}

void updateHeight(node* root){
	int height_left=(root->lchild==NULL)?0:root->lchild->height;
	int height_right=(root->rchild==NULL)?0:root->rchild->height;
	root->height = max(height_left,height_right)+1;
}

void L(node* &root){
	node* tmp=root->rchild;
	root->rchild=tmp->lchild;
	tmp->lchild=root;
	updateHeight(root);// 记得左旋右旋里都要更新树高
	updateHeight(tmp);
	root=tmp;
}

void R(node* &root){
	node* tmp=root->lchild;
	root->lchild=tmp->rchild;
	tmp->rchild=root;
	updateHeight(root);
	updateHeight(tmp);
	root=tmp;
}

void insert(node* &root,int v){
	if(root==NULL){
		root=new node;
		root->height=1;// 记得初始化结点高度
		root->data=v;
		root->lchild=root->rchild=NULL;
		return;
	}
	if(v < root->data){
		insert(root->lchild,v);
		updateHeight(root);
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->lchild) == 1){// LL
				R(root);
			}else if(getBalanceFactor(root->lchild) == -1){// LR
				L(root->lchild);
				R(root);
			}
		}
	}else{
		insert(root->rchild,v);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->rchild) == 1){// RL
				R(root->rchild);
				L(root);
			}else if(getBalanceFactor(root->rchild) == -1){// RR
				L(root);
			}
		}
	}
}

node* create(int data[],int n){
	node* root=NULL;
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	}
	return root;
}

int main(){
	int N;
	cin>>N;
	int data[N];
	for(int i=0;i<N;i++) cin>>data[i];
	node* root=create(data,N);
	cout<<root->data<<endl;
	return 0;
}

