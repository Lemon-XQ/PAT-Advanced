#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> Adj[1001];
bool visit[1001];
int L,ans[1001];
// set<int> ans;// 用set会超时
void dfs(int node,int depth){
	if(depth==L){
		return;
	}
	visit[node]=true;
	for(int i=0;i<Adj[node].size();i++){
		if(visit[Adj[node][i]]==false){
			dfs(Adj[node][i],depth+1);
			ans[Adj[node][i]]=1;// 表示该结点是follower范围内
		}
	}
}

int main(){
	int N,K,num;
	scanf("%d %d",&N,&L);
	for(int i=1;i<=N;i++){
		scanf("%d",&K);
		for(int j=0;j<K;j++){
			scanf("%d",&num);
			Adj[num].push_back(i);
		}
	}
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		int query;
		scanf("%d",&query);
		fill(visit,visit+N+1,false);
		fill(ans,ans+N+1,0);
		int count=0;
		dfs(query,0);
		for(int i=1;i<=N;i++){
		  if(ans[i]!=0) count++;
		}
		printf("%d\n",count);
	}
	return 0;
}

