#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN=1001;

struct node{
	int data;
	node* lchild;
	node* rchild;
	int id;
};

int index=1;
void insert(int x,node* &root){
	if(root==NULL){
		root=new node;
		root->data=x;
		root->lchild=root->rchild=NULL;
		root->id=index++;
		return;
	}
	if(x>root->data){
		insert(x,root->rchild);
	}else{
		insert(x,root->lchild);
	}
}

node* create(int* data,int N){
	node* root=new node;
	root->lchild=root->rchild=NULL;
	root->data=data[0];
	root->id=0;
	for(int i=1;i<N;i++){
		insert(data[i],root);
	}
	return root;
}

int level[MAXN],len=1;
void bfs(node* root){
	queue<node*> q;
	q.push(root);
	level[0]=1;
	int last=q.back()->id;
	while(!q.empty()){
		node* front=q.front();
		q.pop();
		if(front->lchild!=NULL) q.push(front->lchild);
		if(front->rchild!=NULL) q.push(front->rchild);
		if(front->id==last){
			level[len++]=q.size();
			last=q.back()->id;
		}
	}
}

int main(){
	int N;
	cin>>N;
	int data[N];
	for(int i=0;i<N;i++) cin>>data[i];
	node* root=create(data,N);
	bfs(root);
	len--;
	cout<<level[len-1]<<" + "<<level[len-2]<<" = "<<level[len-1]+level[len-2]<<endl;
	return 0;
}
