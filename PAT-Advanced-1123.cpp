#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXV=21;

struct node{
	node* lchild;
	node* rchild;
	int data;
	int height;
	int id;
};

int N;
bool flag=true,visit[MAXV]={false};
void levelOrder(node* root){
	queue<node*> q;
	q.push(root);
	bool first=true;
	while(!q.empty()){
		node* front=q.front();
		q.pop();
		if(!first) cout<<" ";
		cout<<front->data;
		first=false;
		visit[front->id]=true;
		// 判断完全二叉树：考虑左子树为空和右子树为空的情况
		if(front->lchild==NULL || front->rchild==NULL){
		  	if(front->rchild==NULL && front->lchild!=NULL) visit[front->lchild->id]=true;
			for(int i=0;i<N;i++){
				if(visit[i]==false){
					flag=false;
					break;
				}
			}
		}
		if(front->lchild!=NULL){
			visit[front->lchild->id]=true;
			q.push(front->lchild);
		}
		if(front->rchild!=NULL){
			visit[front->rchild->id]=true;
			q.push(front->rchild);
		}
	}
}

int getHeight(node* root){
	if(root==NULL) return 0;
	return root->height;
}

int getBF(node* root){
	return getHeight(root->lchild)-getHeight(root->rchild);
}

void updateHeight(node* &root){
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

void L(node* &root){
	node* tmp=root->rchild;
	root->rchild=tmp->lchild;
	tmp->lchild=root;
	updateHeight(root);
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

int index=0;
void insert(node* &root,int v){
	if(root==NULL){
		root=new node;
		root->id=index++;
		root->data=v;
		root->height=1;// 记得初始化高度！！！
		root->lchild=root->rchild=NULL;
		return;
	}
	if(v < root->data){
		insert(root->lchild,v);
		updateHeight(root);// insert后要立刻更新height
		if(getBF(root)==2){
			if(getBF(root->lchild)==1){// LL
				R(root);
			}else if(getBF(root->lchild)==-1){// LR
				L(root->lchild);
				R(root);
			}
		}
	}else{
		insert(root->rchild,v);
		updateHeight(root);
		if(getBF(root)==-2){
			if(getBF(root->rchild)==1){// RL
				R(root->rchild);
				L(root);
			}else if(getBF(root->rchild)==-1){// RR
				L(root);
			}
		}
	}
}

node* create(int* data,int n){
	node* root=NULL;
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	}
	return root;
}

// 另一种判断完全二叉树的办法
int maxIndex=-1;
void dfs(node* root,int index){
	if(root==NULL) return;
	maxIndex=max(maxIndex,index);
	dfs(root->lchild,2*index);
	dfs(root->rchild,2*index+1);
}

int main(){
	cin>>N;
	int data[N];
	for(int i=0;i<N;i++) cin>>data[i];
	node* root=create(data,N);
	levelOrder(root);
	cout<<endl;
	// 判断完全二叉树
//	dfs(root,1);
//	if(maxIndex==N) cout<<"YES"<<endl;
//	else cout<<"NO"<<endl;
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
