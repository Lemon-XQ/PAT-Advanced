#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
	node* lchild;
	node* rchild;
	int data;
};

vector<int> pre_1,pre_2,post_1,post_2;
void preTransverse_1(node* root){
	if(root==NULL) return;
	pre_1.push_back(root->data);
	preTransverse_1(root->lchild);
	preTransverse_1(root->rchild);
}

void preTransverse_2(node* root){
	if(root==NULL) return;
	pre_2.push_back(root->data);
	preTransverse_2(root->rchild);
	preTransverse_2(root->lchild);
}

void postTransverse_1(node* root){
	if(root==NULL) return;
	postTransverse_1(root->lchild);
	postTransverse_1(root->rchild);
	post_1.push_back(root->data);
}

void postTransverse_2(node* root){
	if(root==NULL) return;
	postTransverse_2(root->rchild);
	postTransverse_2(root->lchild);
	post_2.push_back(root->data);
}
void insert(node* &root,int x){
	if(root==NULL){
		root=new node;
		root->data=x;
		root->lchild=root->rchild=NULL;
		return;
	}
	if(x < root->data){
		insert(root->lchild,x);
	}else{// 大于等于都在右边
		insert(root->rchild,x);
	}
}

node* create(int data[],int n){
	node* root=NULL;
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	}
	return root;
}

bool equal(vector<int> a,int b[]){
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]) return false;
	}
	return true;
}

int main(){
	int N;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++) cin>>arr[i];
	node* root=create(arr,N);
	preTransverse_1(root);
	preTransverse_2(root);
	if(equal(pre_1,arr)){
		cout<<"YES"<<endl;
		postTransverse_1(root);
		for(int i=0;i<post_1.size();i++){
			if(i!=0) cout<<" ";
			cout<<post_1[i];
		}
	}else if(equal(pre_2,arr)){
		cout<<"YES"<<endl;
		postTransverse_2(root);
		for(int i=0;i<post_2.size();i++){
			if(i!=0) cout<<" ";
			cout<<post_2[i];
		}
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}

