#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
	vector<node*> child;
	int data;
};

int level[100]={0};
void levelTransverse(node* root){
	if(root==NULL) return;
	queue<node*> q;
	q.push(root);
	int index=2,last=1;// last表示该层最后一个元素的编号，初始为根节点编号
	level[1]=1;
	while(!q.empty()){
		node* c=q.front();
		q.pop();
		for(int i=0;i<c->child.size();i++){
			q.push(c->child[i]);
		}
		if(c->data==last){// 说明该层已经遍历完
			level[index++]=q.size();
			last=q.back()->data;
		}
	}
}

int main(){// 统计每层的元素数，取最大
	int N,M;
	cin>>N>>M;
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
	int index=1,max=0;
	for(int i=1;i<100;i++){
		if(level[i]!=0 && level[i]>max){
			max=level[i];
			index=i;
		}
	}
	printf("%d %d\n",max,index);
	return 0;
}

