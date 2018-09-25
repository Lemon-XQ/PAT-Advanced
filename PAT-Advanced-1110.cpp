#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
	node* lchild;
	node* rchild;
	int data;
};

bool flag=true;
int N;
int bfs(node* root){
	queue<node*> q;
	q.push(root);
	int last;
	bool visit[21]={false};
	while(!q.empty()){
		node* front=q.front();
		q.pop();
		last=front->data;
		visit[last]=true;
		if(front->lchild==NULL){// 完全二叉树不一定左右儿子都有，但是有右儿子就一定有左儿子
			for(int i=0;i<N;i++){// 仍有未遍历到的结点，说明不是完全二叉树
				if(visit[i]==false){
					flag=false;
					break;
				}
			}
		}
		if(front->lchild!=NULL){
			q.push(front->lchild);
			visit[front->lchild->data]=true;
		}
		if(front->rchild!=NULL){
			q.push(front->rchild);
			visit[front->rchild->data]=true;
		}
	}
	return last;
}

int main(){
	cin>>N;
	node* arr=new node[N];
	int count[21]={0},root;
	for(int i=0;i<N;i++){
		string a,b;
		cin>>a>>b;
		arr[i].lchild=(a=="-")?NULL:&arr[atoi(a.c_str())];
		arr[i].rchild=(b=="-")?NULL:&arr[atoi(b.c_str())];
		arr[i].data=i;
		if(a!="-") count[atoi(a.c_str())]++;
		if(b!="-") count[atoi(b.c_str())]++;
	}
	for(int i=0;i<N;i++){
		if(count[i]==0){
			root=i;
			break;
		}
	}
	int last=bfs(&arr[root]);
	if(flag) cout<<"YES "<<last<<endl;
	else cout<<"NO "<<root<<endl;
    return 0;
}
