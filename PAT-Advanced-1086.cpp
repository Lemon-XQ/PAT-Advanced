#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct node{
	node* lchild;
	node* rchild;
	int data;
};

bool first=false;
void postTransverse(node* root){
	if(root==NULL) return;
	postTransverse(root->lchild);
	postTransverse(root->rchild);
	if(first){
		cout<<" ";
	}
	cout<<root->data;
	first=true;
}

int pre[30],in[30];
node* generateTree(int preL,int preR,int inL,int inR){
	if(preL>preR) return NULL;
	node* root=new node;
	root->data=pre[preL];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==pre[preL]){
			break;
		}
	}
	int len=k-inL;
	root->lchild=generateTree(preL+1,preL+len,inL,k-1);
	root->rchild=generateTree(preL+len+1,preR,k+1,inR);
	return root;
}

int main(){
	int N;
    cin>>N; getchar();
    stack<int> s;// 入栈顺序就是先序遍历
    int index_1=0,index_2=0;
    for(int i=0;i<2*N;i++){
    	string str;
    	getline(cin,str);
    	if(str.length()>3){
    		int num=atoi(str.substr(5,str.length()-5).c_str());
			pre[index_1++]=num;
			s.push(num);
		}else{
			in[index_2++]=s.top();
			s.pop();
		}
	}
	node* root=generateTree(0,N-1,0,N-1);
	postTransverse(root);
	return 0;
}

