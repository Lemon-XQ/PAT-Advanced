#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXV=31;

int N,in[MAXV],post[MAXV];

struct node{
	int data;
	node* lchild;
	node* rchild;
};

vector<int> ans;
int level[MAXV]={0},height=1;
void zigzagg(node* root){
	queue<node*> q;
	q.push(root);
	int last=q.back()->data;
	level[0]=1;
	while(!q.empty()){
		node* front=q.front();
		q.pop();
		ans.push_back(front->data);
		if(front->lchild!=NULL) q.push(front->lchild);
		if(front->rchild!=NULL) q.push(front->rchild);
		if(last==front->data){
			level[height++]=q.size();
			last=q.back()->data;
		}
	}
}

node* create(int postL,int postR,int inL,int inR){
	if(postL>postR){
		return NULL;
	}
	node* root=new node;
	root->data=post[postR];
	root->lchild=root->rchild=NULL;
	int k;
	for(k=0;k<=inR;k++){
		if(in[k]==post[postR]) break;
	}
	int len=k-inL;
	root->lchild=create(postL,postL+len-1,inL,k-1);
	root->rchild=create(postL+len,postR-1,k+1,inR);
	return root;
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++) cin>>in[i];
	for(int i=0;i<N;i++) cin>>post[i];
	node* root=create(0,N-1,0,N-1);
	zigzagg(root);
	// Å¼Êý²ãreverse
	int offset=0;
	for(int i=0;i<height;i++){
		if(i%2==0) reverse(ans.begin()+offset,ans.begin()+offset+level[i]);
		offset+=level[i];
	}
	for(int i=0;i<ans.size();i++){
		if(i!=0) cout<<" ";
		cout<<ans[i];
	}
	return 0;
}
