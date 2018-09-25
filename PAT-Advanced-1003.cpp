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
	int v;
	node(int _v,int _weight){
		v=_v; weight=_weight;
	}
};

vector<node> Adj[501];
int N,M,C1,C2;
int d[501],w[501],rescue[501];// d为第一标尺，w为第二标尺
int num[501];// num[u]表示到u的最短路径数
bool visit[501]={false};
void DJ(int start){
	fill(d,d+N,INF);
	fill(w,w+N,0);
	fill(num,num+N,0);
	d[start]=0;
	w[start]=rescue[start];// 表示从起点到start的最大救援人数
	num[start]=1;
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
					w[v]=w[u]+rescue[v];
					num[v]=num[u];
				 }else if(d[u]+Adj[u][j].weight==d[v]){// 找到多条最短路径
					if(w[u]+rescue[v]>w[v]) w[v]=w[u]+rescue[v];// 第二标尺
				 	num[v]+=num[u];
				 }
			}
		}
	}
}

int main(){
	cin>>N>>M>>C1>>C2;
	for(int i=0;i<N;i++){
		cin>>rescue[i];
	}
	for(int i=0;i<M;i++){
		int a,b,L;
		cin>>a>>b>>L;
		Adj[a].push_back(node(b,L));
		Adj[b].push_back(node(a,L));
	}
	DJ(C1);
	cout<<num[C2]<<" "<<w[C2]<<endl;
	return 0;
}

