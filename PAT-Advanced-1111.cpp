#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXV=501;
const int INF=0x3fffffff;

struct node{
	int v;
	int weight;
	int time;
	node(int _v,int _w,int _t){
		v=_v; weight=_w; time=_t;
	}
};

vector<node> Adj[MAXV];
bool visit[MAXV]={false};
int N,M,d[MAXV],t[MAXV],pre[MAXV];
void DJ_dis(int start){
	fill(d,d+N,INF);
	fill(t,t+N,INF);
	for(int i=0;i<N;i++) pre[i]=i;
	d[start]=0;
	for(int i=0;i<N;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<N;j++){
			if(visit[j]==false && d[j]<MIN){
				MIN=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		visit[u]=true;
		for(int j=0;j<Adj[u].size();j++){
			int v=Adj[u][j].v;
			if(visit[v]==false){
				if(d[u]+Adj[u][j].weight<d[v]){
					t[v]=t[u]+Adj[u][j].time;
					d[v]=d[u]+Adj[u][j].weight;
					pre[v]=u;
				}else if(d[u]+Adj[u][j].weight==d[v] && t[u]+Adj[u][j].time<t[v]){
					t[v]=t[u]+Adj[u][j].time;
					pre[v]=u;
				}
			}
			
		}
	}
}

vector<int> pre2[MAXV];
void DJ_time(int start){
	fill(t,t+N,INF);
	fill(visit,visit+N,false);
	t[start]=0;
	for(int i=0;i<N;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<N;j++){
			if(visit[j]==false && t[j]<MIN){
				MIN=t[j];
				u=j;
			}
		}
		if(u==-1) return;
		visit[u]=true;
		for(int j=0;j<Adj[u].size();j++){
			int v=Adj[u][j].v;
			if(visit[v]==false){
				if(t[u]+Adj[u][j].time<t[v]){
					t[v]=t[u]+Adj[u][j].time;
					pre2[v].clear();
					pre2[v].push_back(u);
				}else if(t[u]+Adj[u][j].time==t[v]){
					pre2[v].push_back(u);
				}
			}

		}
	}
}

vector<int> ans_1,ans_2,tmp;
void dfs_dis(int start,int v){
	if(start==v){
		ans_1.push_back(v);
		return;
	}
	dfs_dis(start,pre[v]);
	ans_1.push_back(v);
}

int MIN=INF;
void dfs_time(int start,int v,int len){
	if(start==v){
		tmp.push_back(v);
		if(len<MIN){
			MIN=len;
			ans_2=tmp;
		}
		tmp.pop_back();
		return;
	}
	for(int i=0;i<pre2[v].size();i++){
		tmp.push_back(v);
		dfs_time(start,pre2[v][i],len+1);
		tmp.pop_back();
	}
}

int main(){
	cin>>N>>M;
	int start,des;
	for(int i=0;i<M;i++){
		int v1,v2,flag,len,time;
		cin>>v1>>v2>>flag>>len>>time;
		Adj[v1].push_back(node(v2,len,time));
		if(flag==0) Adj[v2].push_back(node(v1,len,time));
	}
	cin>>start>>des;
	DJ_dis(start);
	dfs_dis(start,des);
	DJ_time(start);
	dfs_time(start,des,0);
	reverse(ans_2.begin(),ans_2.end());
	if(ans_1==ans_2){
		printf("Distance = %d; Time = %d: ",d[des],t[des]);
		for(int i=0;i<ans_1.size();i++){
			if(i!=0) cout<<" -> ";
			cout<<ans_1[i];
		}
	}else{
		printf("Distance = %d: ",d[des]);
		for(int i=0;i<ans_1.size();i++){
			if(i!=0) cout<<" -> ";
			cout<<ans_1[i];
		}
		printf("\nTime = %d: ",t[des]);
		for(int i=0;i<ans_2.size();i++){
			if(i!=0) cout<<" -> ";
			cout<<ans_2[i];
		}
	}
    return 0;
}
