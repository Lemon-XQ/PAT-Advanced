#include <iostream>
#include <algorithm>
#include <vector>

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
int N,M,Cmax,Sp;
int d[501],w[501],capacity[501]={0};// d为第一标尺，w为第二标尺
bool visit[501]={false};
vector<int> pre[501];// pre[v]表示从起点到v的最短路径上v的前一个顶点
void DJ(int start){
	fill(d,d+N+1,INF);
	d[start]=0;
	for(int i=0;i<=N;i++){
		int u=-1, min=INF;
		for(int j=0;j<=N;j++){
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
					pre[v].clear();
					pre[v].push_back(u);
				 }else if(d[u]+Adj[u][j].weight==d[v]){// 找到多条最短路径
					pre[v].push_back(u);
				 }
			}
		}
	}
}

int minNeed=INF,minRemain=INF;
vector<int> tmpPath,path;// 存储路径
void dfs(int start,int v){
	if(v==start){
		tmpPath.push_back(start);
		int need=0,remain=0;// tmpPath上需要携带的数目，需要带回的数目
		for(int i=tmpPath.size()-1;i>=0;i--){// 必须从start结点开始
			int id=tmpPath[i];
			if(capacity[id]>0){// 需要带回
				remain += capacity[id];
			}else{// 需要携带
				if(remain>abs(capacity[id])) remain-=abs(capacity[id]);
				else{
					need+=abs(capacity[id])-remain;
					remain=0;
				}
			}
		}
		if(need<minNeed){// 第二标尺是need
			minNeed=need;
			minRemain=remain;
			path=tmpPath;
		}else if(need==minNeed && remain<minRemain){// 第三标尺是remain
			minRemain=remain;
			path=tmpPath;
		}
		tmpPath.pop_back();// 弹出start结点
		return;
	}
	for(int i=0;i<pre[v].size();i++){
		tmpPath.push_back(v);
		dfs(start,pre[v][i]);
		tmpPath.pop_back();
	}
}

int main(){
	cin>>Cmax>>N>>Sp>>M;
	for(int i=1;i<=N;i++){
		cin>>capacity[i];
		capacity[i]-=Cmax/2;
	}
	for(int i=0;i<M;i++){
		int a,b,L;
		cin>>a>>b>>L;
		Adj[a].push_back(node(b,L));
		Adj[b].push_back(node(a,L));
	}
	DJ(0);
	dfs(0,Sp);
	cout<<minNeed<<" ";
	reverse(path.begin(),path.end());
	for(int i=0;i<path.size();i++){
		if(i!=0) cout<<"->";
		cout<<path[i];
	}
	cout<<" "<<minRemain<<endl;
	return 0;
}


// 两个测试点过不了，题意要求的是去的路上就要调整好路上所有的点，回来时不调整
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//const int INF=0x3fffffff;
//
//struct node{
//	int weight;
//	int v;
//	node(int _v,int _weight){
//		v=_v; weight=_weight;
//	}
//};
//
//vector<node> Adj[501];
//int N,M,Cmax,Sp;
//int d[501],w[501],capacity[501]={0};// d为第一标尺，w为第二标尺
//bool visit[501]={false};
//int need;
//int pre[501];// pre[v]表示从起点到v的最短路径上v的前一个顶点
//void DJ(int start){
//	fill(d,d+N+1,INF);
//	fill(w,w+N+1,0);
//	for(int i=0;i<=N;i++) pre[i]=i;
//	d[start]=0;
//	w[start]=capacity[start];// 表示从起点到start的最大救援人数
//	for(int i=0;i<=N;i++){
//		int u=-1, min=INF;
//		for(int j=0;j<=N;j++){
//			if(visit[j]==false && d[j]<min){
//				min=d[j];
//				u=j;
//			}
//		}
//		if(u==-1) return;
//		visit[u]=true;
//		for(int j=0;j<Adj[u].size();j++){
//			int v=Adj[u][j].v;
//			if(visit[v]==false){
//				 if(d[u]+Adj[u][j].weight<d[v]){
//					d[v]=d[u]+Adj[u][j].weight;
//					w[v]=w[u]+capacity[v];
//					pre[v]=u;
//				 }else if(d[u]+Adj[u][j].weight==d[v]){// 找到多条最短路径
//					if(need<0 && w[u]+capacity[v]>w[v] || need>=0 && w[u]+capacity[v]<w[v]){
//					 	w[v]=w[u]+capacity[v];// 第二标尺
//					 	pre[v]=u;
//					}
//				 }
//			}
//		}
//	}
//}
//
//
//
//vector<int> ans;
//void dfs(int start,int v){
//	if(v==start){
//		ans.push_back(start);
//		return;
//	}
//	dfs(start,pre[v]);
//	ans.push_back(v);
//}
//
//int main(){
//	cin>>Cmax>>N>>Sp>>M;
//	for(int i=1;i<=N;i++){
//		cin>>capacity[i];
//	}
//	for(int i=0;i<M;i++){
//		int a,b,L;
//		cin>>a>>b>>L;
//		Adj[a].push_back(node(b,L));
//		Adj[b].push_back(node(a,L));
//	}
//	int send,back;
//	need=capacity[Sp]-Cmax/2;
//	capacity[Sp]=0;
//	for(int i=1;i<=N;i++) if(i!=Sp) capacity[i]-=Cmax/2;
//	DJ(0);
//	dfs(0,Sp);
//	if(need<0){
//		send=(w[Sp]>-need)?0:-need-w[Sp];
//		back=(w[Sp]>-need)?w[Sp]+need:0;
//	}else{
//		if(w[Sp]<=0 && -w[Sp]<=need){
//			send=0;
//			back=need+w[Sp];
//		}else if(w[Sp]<=0 && -w[Sp]>need){
//			send=-w[Sp]-need;
//			back=0;
//		}else if(w[Sp]>0){
//			send=0;
//			back=w[Sp]+need;
//		}
//	}
//	cout<<send<<" ";
//	for(int i=0;i<ans.size();i++){
//		if(i!=0) cout<<"->";
//		cout<<ans[i];
//	}
//	cout<<" "<<back<<endl;
//	return 0;
//}

