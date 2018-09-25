#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
	vector<node*> child;
	int data;
};

double P,r;
vector<double> ans;
// len表示当前高度
void preTransverse(node* root,int len){
	if(root==NULL) return;
	if(root->child.size()==0)// 叶子结点
		ans.push_back(P*pow(1+0.01*r,len));
	for(int i=0;i<root->child.size();i++){
		preTransverse(root->child[i],len+1);
	}
}

int main(){
	int N;
	cin>>N>>P>>r;
	node* arr=new node[N];
	int root;
	for(int i=0;i<N;i++){
		int num;
		cin>>num;
		if(num==-1) root=i;
		else arr[num].child.push_back(&arr[i]);
	}
	preTransverse(&arr[root],0);
	sort(ans.begin(),ans.end(),greater<double>());
	int count=1;
	for(int i=0;i<ans.size()-1;i++){
		if(ans[i]==ans[i+1]) count++;
		else break;
	}
	printf("%.2lf %d\n",ans[0],count);
	return 0;
}

