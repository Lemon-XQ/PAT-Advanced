#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
	vector<node*> child;
	int data;
};

double ans=0;
double P,r;
// len表示当前高度
void preTransverse(node* root,int len){
	if(root==NULL) return;
	if(root->data!=-1){
		ans+=root->data*P*pow(1+0.01*r,len);
	}
	for(int i=0;i<root->child.size();i++){
		preTransverse(root->child[i],len+1);
	} 
}

int main(){
	int N;
	cin>>N>>P>>r;
	node* arr=new node[N];
	for(int i=0;i<N;i++){
		int k,num;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>num;
			arr[i].child.push_back(&arr[num]);
			arr[i].data=-1;
		}
		if(k==0){
			cin>>num;
			arr[i].data=num;
		}
	}
	preTransverse(&arr[0],0);
	printf("%.1lf\n",ans);
	return 0;
}

