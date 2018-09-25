#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int MAXV=1001;

struct node{
	int data;
	node* lchild;
	node* rchild;
	node(int _data){
		data=_data;
		lchild=rchild=NULL;
	}
};

bool first=true;
void postOrder(node* root){
	if(root==NULL) return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	if(!first) cout<<" ";
	cout<<root->data;
	first=false;
}

int M,N;
int data[MAXV];
node* create(int index){
	if(index>N) return NULL;
	node* root=new node(data[index]);
	root->lchild=create(index*2);
	root->rchild=create(index*2+1);
	return root;
}

bool minHeap(){
	for(int low=N/2;low>=1;low--){
		int i=low,j=i*2;
		while(j<=N){
			if(j+1<=N && data[j+1]<data[j]){
				j=j+1;
			}
			if(data[j]<data[i]){// 最小堆根节点要小于孩子结点中最小的
				return false;
			}else{
				break;
			}
		}
	}
	return true;
}

bool maxHeap(){
	for(int low=N/2;low>=1;low--){
		int i=low,j=i*2;
		while(j<=N){
			if(j+1<=N && data[j+1]>data[j]){
				j=j+1;
			}
			if(data[j]>data[i]){
				return false;
			}else{
				break;
			}
		}
	}
	return true;
}

int main(){
	cin>>M>>N;
	for(int i=0;i<M;i++){
		for(int j=1;j<=N;j++){
			cin>>data[j];
		}
		node* root=create(1);
		// 判断heap（从下往上，根节点和孩子结点比较）
		if(minHeap()) cout<<"Min Heap"<<endl;
		else if(maxHeap()) cout<<"Max Heap"<<endl;
		else cout<<"Not Heap"<<endl;
		// post遍历
		first=true;
		postOrder(root);
		cout<<endl;
	}
	return 0;
}
