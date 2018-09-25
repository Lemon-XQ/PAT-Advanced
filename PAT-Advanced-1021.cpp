#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> Adj[10001];
bool visit[10001];
void dfs(int index){
	visit[index]=true;
	for(int i=0;i<Adj[index].size();i++){
		// 去掉访问过的结点
		if(visit[Adj[index][i]]==false) dfs(Adj[index][i]);
	}
}

int root,maxDepth=1;
vector<int> ans;
void solve(int node,int depth){
	// 叶子结点的判定：只有一个邻接且邻接的点不是根结点
	if(Adj[node].size()==1 && Adj[node][0]!=root && depth>maxDepth){
		maxDepth=depth;
	}
	visit[node]=true;
	for(int i=0;i<Adj[node].size();i++){
		if(visit[Adj[node][i]]==false) solve(Adj[node][i],depth+1);
	}
}

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	int block=0;
	for(int i=1;i<=N;i++){
		if(visit[i]==false){
			dfs(i);
			block++;
		}
	}
	// 连通块数不为1：不是树
	if(block!=1) cout<<"Error: "<<block<<" components"<<endl;
	else{
		for(int i=1;i<=N;i++){
			fill(visit,visit+N+1,false);
			maxDepth=1;
			root=i;
			solve(i,1);
			ans.push_back(maxDepth);
		}
		int max=*max_element(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++){
			if(ans[i]==max) cout<<i+1<<endl;
		}
	}

	return 0;
}

