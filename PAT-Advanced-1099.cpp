#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct node{
	node* lchild;
	node* rchild;
	int data;
};

void levelTransverse(node* root){
	if(root==NULL) return;
	queue<node*> q;
	q.push(root);
	bool first=true;
	while(!q.empty()){
		node* c=q.front();
		q.pop();
		if(!first) cout<<" ";
		cout<<c->data;
		first=false;
		if(c->lchild!=NULL) q.push(c->lchild);
		if(c->rchild!=NULL) q.push(c->rchild);
	}
}

int data[101],index=0;
void inOrder(node* root){
	if(root==NULL) return;
	inOrder(root->lchild);
	root->data=data[index++];
	inOrder(root->rchild);
}

int main(){
	int N;
	cin>>N;
	node* arr=new node[N];
	for(int i=0;i<N;i++){
		int a,b;
		cin>>a>>b;
		arr[i].lchild=(a==-1)?NULL:&arr[a];
		arr[i].rchild=(b==-1)?NULL:&arr[b];
	}
	for(int i=0;i<N;i++) cin>>data[i];
	sort(data,data+N);
	inOrder(&arr[0]);
	levelTransverse(&arr[0]);
	return 0;
}

