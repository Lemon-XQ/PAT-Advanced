#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
	vector<node*> child;
	int data;
};

int level[100];
void levelTransverse(node* root){
	if(root==NULL) return;
	queue<node*> q;
	q.push(root);
	int leaf=0,index=1,last=1;
	if(root->child.size()==0){
		level[0]=1; return;
	}
	else level[0]=0;
	while(!q.empty()){
		node* c=q.front();
		q.pop();
		for(int i=0;i<c->child.size();i++){
			q.push(c->child[i]);
			if(c->child[i]->child.size()==0) leaf++;
		}
		if(c->data==last){// 该层结束
			level[index++]=leaf;
			leaf=0;
			last=q.back()->data;
		}
	}
	level[index-1]=-1;// 去除最后一层
}

int main(){
	int N,M;
	cin>>N>>M;
	fill(level,level+100,-1);
	node* arr=new node[N+1];
	arr[1].data=1;
	for(int i=0;i<M;i++){
		int num,K;
		cin>>num>>K;
		for(int j=0;j<K;j++){
			int a;
			cin>>a;
			arr[num].child.push_back(&arr[a]);
			arr[a].data=a;
		}
	}
	levelTransverse(&arr[1]);
	for(int i=0;i<100;i++){
		if(level[i]!=-1){
		  if(i!=0) cout<<" ";
		  cout<<level[i];
		}
	}
	return 0;
}

