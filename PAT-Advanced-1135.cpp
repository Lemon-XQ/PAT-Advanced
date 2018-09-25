#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>

using namespace std;

const int MAXV=31;
const int INF=0x3fffffff;

struct node{
	node* lchild;
	node* rchild;
	int data;
	int height;
	node(){
		lchild=rchild=NULL;
		height=1;
	}
};

int pre[MAXV];
int N;
node* create(int preL,int preR){
	if(preL>preR) return NULL;
	node* root=new node;
	root->data=pre[preL];
	if(root->data<0) root->height=0;
	int i;
	for(i=preL+1;i<=preR;i++){
		if(abs(pre[i])>abs(pre[preL])) break;
	}
	int len=i-preL;
	root->lchild=create(preL+1,preL+len-1);
	root->rchild=create(preL+len,preR);
	return root;
}

bool flag=true;
vector<node*> levelPath;
void levelOrder(node* root){
	queue<node*> q;
	q.push(root);
	levelPath.clear();
	int last=q.back()->data,level=1;
	while(!q.empty()){
		node* front=q.front();
		q.pop();
		levelPath.push_back(front);
		// 第一层不能为红色结点，红色结点的孩子必须为黑色结点（但是黑色结点的孩子可以为黑色结点/红色结点）
		if(front->data<0){// red
			if(level==1 ||
			   front->lchild!=NULL && front->lchild->data<0 ||
			   front->rchild!=NULL && front->rchild->data<0){
					flag=false;
					break;
			   }
		}
		if(front->lchild!=NULL) q.push(front->lchild);
		if(front->rchild!=NULL) q.push(front->rchild);
		if(last==front->data){
			level++;
			last=q.back()->data;
		}
	}
}

int getHeight(node* root){
	if(root==NULL) return 0;
	return root->height;
}

void updateHeight(){
	reverse(levelPath.begin(),levelPath.end());
	for(int i=0;i<levelPath.size();i++){
		node* &root=levelPath[i];
		if(root->lchild!=NULL || root->rchild!=NULL){
			if(getHeight(root->lchild)!=getHeight(root->rchild)){
				flag=false;
				break;
			}
		}
		root->height=max(getHeight(root->lchild),getHeight(root->rchild));
		if(root->data>0) root->height++;
	}
}

int main(){
	int K;
	cin>>K;
	for(int i=0;i<K;i++){
		cin>>N;
		for(int j=0;j<N;j++) cin>>pre[j];
		node* root=create(0,N-1);
		flag=true;
		levelOrder(root);
		if(flag){
			updateHeight();
			if(flag) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		} 
		else cout<<"No"<<endl;
	}
	return 0;
}
