#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

const int MAXV=10001;
const int INF=0x3fffffff;

struct node{
	int v,weight;
	int line;
	node(int _v,int _line){
		weight=1;
		v=_v;
		line=_line;
	}
};

int N,d[MAXV],total;
vector<node> Adj[MAXV];
vector<int> pre[MAXV];
bool visit[MAXV]={false};
set<int> s;
void DJ(int start){
	for(int i=0;i<MAXV;i++) pre[i].clear();
	fill(visit,visit+MAXV,false);
	fill(d,d+MAXV,INF);
	d[start]=0;
	for(int i=0;i<total;i++){
		int u=-1,MIN=INF;
		for(set<int>::iterator it=s.begin();it!=s.end();it++){
			if(visit[*it]==false && d[*it]<MIN){
				u=*it;
				MIN=d[*it];
			}
		}
		if(u==-1) return;
		visit[u]=true;
		for(int j=0;j<Adj[u].size();j++){
			int v=Adj[u][j].v;
			if(visit[v]==false){
				if(d[u]+Adj[u][j].weight<d[v]){
					d[v]=d[u]+Adj[u][j].weight;
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+Adj[u][j].weight==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

map<pair<int,int>,int> lines;
vector<int> tmp,ans;
int MIN=INF,minCnt=INF;
void dfs(int current,int des,int cnt){
	if(current==des){
//		tmp.push_back(des);
		int transfer=0,pre_line=0;
		for(int i=0;i<tmp.size()-1;i++){
			int line=lines[make_pair(tmp[i],tmp[i+1])];
			if(line!=pre_line){
				pre_line=line;
				transfer++;
			}
		}
		if(cnt<minCnt || (cnt==minCnt && transfer<MIN)){
			minCnt=cnt;
			MIN=transfer;
			ans=tmp;
		}
//		tmp.pop_back();///
		return;
	}
	for(int i=0;i<Adj[current].size();i++){////
		int v=Adj[current][i].v;
		if(visit[v]==false){
			visit[v]=true;
			tmp.push_back(v);
			dfs(v,des,cnt+1);
			tmp.pop_back();
			visit[v]=false;
		}
	}
//	for(int i=0;i<pre[v].size();i++){////
//		tmp.push_back(v);
//		dfs(start,pre[v][i]);
//		tmp.pop_back();
//	}
}

int main(){
	cin>>N;
	int M,K,S[MAXV];
//	vector<int> station[MAXV];
	for(int i=1;i<=N;i++){
		cin>>M;
		for(int j=0;j<M;j++){
			cin>>S[j];
//			station[S[j]].push_back(i);
//			s.insert(S[j]);
		}
		for(int j=0;j<M-1;j++){
			lines[make_pair(S[j],S[j+1])]=i;// 存储某段线路属于的line编号
			lines[make_pair(S[j+1],S[j])]=i;
			Adj[S[j]].push_back(node(S[j+1],i));
			Adj[S[j+1]].push_back(node(S[j],i));
		}
	}
//	total=s.size();
	cin>>K;
	for(int i=0;i<K;i++){
		int start,des;
		cin>>start>>des;
		tmp.clear();
		MIN=INF;
		minCnt=INF;
		fill(visit,visit+MAXV,false);
//		DJ(start);// 最后一个测试点超时
		tmp.push_back(start);// 要先push开始结点
		dfs(start,des,0);
		cout<<minCnt<<endl;
//		cout<<d[des]<<endl;
		int pre_line=0,line;
//		reverse(ans.begin(),ans.end());
		for(int j=0;j<ans.size()-1;j++){// 路径上的每个站点
			line=lines[make_pair(ans[j],ans[j+1])];
			if(line!=pre_line){
				if(pre_line!=0) printf("%04d.\n",ans[j]);
				pre_line=line;
				printf("Take Line#%d from %04d to ",line,ans[j]);
			}
		}
		printf("%04d.\n",ans[ans.size()-1]);
	}
	return 0;
}
