#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct node{
	node* lchild;
	node* rchild;
	int data;
};

bool first=false;
void inTransverse(node* root){
	if(root==NULL) return;
	inTransverse(root->rchild);
	if(first){
		cout<<" ";
	}
	cout<<root->data;
	first=true;
	inTransverse(root->lchild);
}

void levelTransverse(node* root){
	if(root==NULL) return;
	queue<node*> q;
	q.push(root);
	bool first=false;
	while(!q.empty()){
		node* front=q.front();
		q.pop();
		if(first) cout<<" ";
		cout<<front->data;
		first=true;
		if(front->rchild!=NULL) q.push(front->rchild);
		if(front->lchild!=NULL) q.push(front->lchild);
	}
	cout<<endl;
}

int main(){
	int N;
    cin>>N;
    node* arr=new node[N];
    int index[N],i;
    fill(index,index+N,0);
	for(int i=0;i<N;i++){
		string a,b;
		cin>>a>>b;
		arr[i].data=i;
		arr[i].lchild=(a=="-")?NULL:&arr[atoi(a.c_str())];
		arr[i].rchild=(b=="-")?NULL:&arr[atoi(b.c_str())];
		if(isdigit(a[0])) index[atoi(a.c_str())]=1;
		if(isdigit(b[0])) index[atoi(b.c_str())]=1;
	}
	for(i=0;i<N;i++){
		if(index[i]==0) break;// root结点（没有出现过的数字）
	}
	levelTransverse(&arr[i]);
	inTransverse(&arr[i]);
	return 0;
}

