#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
	vector<node*> child;
	int data;
	int weight;
};

vector<vector<int> > ans;
vector<int> tmp;// tmp存储每次的路径，符合要求则存入ans
int S;
void preTransverse(node* root,int sum){
	if(root==NULL) return;
	if(root->child.size()==0 && sum==S){
		ans.push_back(tmp);
	}
	for(int i=0;i<root->child.size();i++){
		tmp.push_back(root->child[i]->weight);
		preTransverse(root->child[i],sum+root->child[i]->weight);
		tmp.pop_back();
	}
}

bool comp(vector<int> a,vector<int> b){
	bool flag=false;
	for(int i=0;i<min(a.size(),b.size());i++){
		if(a[i]!=b[i]){
			flag=true;
			return a[i]>b[i];
		}
	}
	if(!flag) return a.size()-b.size();
}

int main(){
	int N,M;
	cin>>N>>M>>S;
	node* arr=new node[N];
	for(int i=0;i<N;i++) cin>>arr[i].weight;
	arr[0].data=0;
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
	preTransverse(&arr[0],arr[0].weight);// sum初值为根节点权重
	sort(ans.begin(),ans.end(),comp);
	for(int i=0;i<ans.size();i++){
		cout<<arr[0].weight;// 每条路径第一个结点一定是根节点
		for(int j=0;j<ans[i].size();j++){
			cout<<" "<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}

