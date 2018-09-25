#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

const int INF=0x3fffffff;

struct node{
	int weight;
	int cost;// ��Ȩ���ڶ���ߣ�
	int v;
	node(int _v,int _weight,int _cost){
		v=_v; weight=_weight; cost=_cost;
	}
};

vector<node> Adj[501];
int N,M,S,D;
int d[501],w[501];// dΪ��һ��ߣ�wΪ�ڶ����
bool visit[501]={false};
int need;
int pre[501];// pre[v]��ʾ����㵽v�����·����v��ǰһ������
void DJ(int start){
	fill(d,d+N,INF);
	fill(w,w+N,0);
	for(int i=0;i<N;i++) pre[i]=i;
	d[start]=0;
	for(int i=0;i<N;i++){
		int u=-1, min=INF;
		for(int j=0;j<N;j++){
			if(visit[j]==false && d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		visit[u]=true;
		for(int j=0;j<Adj[u].size();j++){
			int v=Adj[u][j].v;
			if(visit[v]==false){
				 if(d[u]+Adj[u][j].weight<d[v]){
					d[v]=d[u]+Adj[u][j].weight;
					w[v]=w[u]+Adj[u][j].cost;
					pre[v]=u;
				 }else if(d[u]+Adj[u][j].weight==d[v]){// �ҵ��������·��
					if(w[u]+Adj[u][j].cost<w[v]){
					 	w[v]=w[u]+Adj[u][j].cost;// �ڶ����
					 	pre[v]=u;
					}
				 }
			}
		}
	}
}

vector<int> ans;
void dfs(int start,int v){
	if(v==start){
		ans.push_back(start);
		return;
	}
	dfs(start,pre[v]);
	ans.push_back(v);
}

int main(){
	cin>>N>>M>>S>>D;
	for(int i=0;i<M;i++){
		int a,b,dis,cost;
		cin>>a>>b>>dis>>cost;
		Adj[a].push_back(node(b,dis,cost));
		Adj[b].push_back(node(a,dis,cost));
	}
	DJ(S);
	dfs(S,D);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<d[D]<<" "<<w[D]<<endl;
	return 0;
}
