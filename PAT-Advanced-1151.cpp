#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAXV=10001;

struct node{
	node* lchild;
	node* rchild;
	int data;
	node(){
		lchild=rchild=NULL;
	}
};

int in[MAXV],pre[MAXV];
map<int,int> m;
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

vector<int> path,ans;
bool flag=false;
void dfs(node* root,int v){
	if(root==NULL) return;
	if(root->data==v){
		flag=true;
		path.push_back(root->data);
		ans=path;
		path.pop_back();
		return;
	}else{
		path.push_back(root->data);
		dfs(root->lchild,v);
		if(flag) return;
		path.pop_back();
		path.push_back(root->data);
		dfs(root->rchild,v);
		if(flag) return;
		path.pop_back();
	}
}

int main(){
	int M,N;
	cin>>M>>N;
	for(int i=0;i<N;i++){
		cin>>in[i];
		m[in[i]]=i;// 记录某个结点是否出现过
	}
	for(int i=0;i<N;i++) cin>>pre[i];
	node* root=create(0,N-1,0,N-1);// 根据先序中序序列建树
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
		if(m.count(u)==0 && m.count(v)==0) printf("ERROR: %d and %d are not found.\n",u,v);
		else if(m.count(u)==0) printf("ERROR: %d is not found.\n",u);
		else if(m.count(v)==0) printf("ERROR: %d is not found.\n",v);
		else{
			// dfs分别遍历u,v结点，得到两条路径
			vector<int> pu,pv;
			path.clear();
			flag=false;
			dfs(root,u);
			pu=ans;
			path.clear();
			flag=false;
			dfs(root,v);
			pv=ans;
			// 找两条路径第一个不同的结点
			int j;
			for(j=0;j<min(pu.size(),pv.size());j++){
				if(pu[j]!=pv[j]) break;
			}
			if(j!=min(pu.size(),pv.size())) printf("LCA of %d and %d is %d.\n",u,v,pu[j-1]);
			else if(pu.size()<pv.size()) printf("%d is an ancestor of %d.\n",u,v);
			else printf("%d is an ancestor of %d.\n",v,u);
		}
	}
	return 0;
}
