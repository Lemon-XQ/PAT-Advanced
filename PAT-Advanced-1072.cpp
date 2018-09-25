#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

const int INF=0x3fffffff;
const int MAXV=1020;

struct node{
	int weight;
	int v;
	node(int _v,int _weight){
		v=_v; weight=_weight;
	}
};

vector<node> Adj[MAXV];
int N,M,K,D;
int d[MAXV],w[MAXV];// d为第一标尺，w为第二标尺
bool visit[MAXV]={false};
void DJ(int start){
	fill(d,d+MAXV,INF);
	fill(visit,visit+MAXV,false);
	d[start]=0;
	for(int i=0;i<N+M;i++){
		int u=-1, min=INF;
		for(int j=1;j<=N+M;j++){
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
				 }
			}
		}
	}
}

int main(){
	cin>>N>>M>>K>>D;
	int offset=N;
	for(int i=0;i<K;i++){
		int dis,aa,bb;
		string a,b;
		cin>>a>>b>>dis;
		if(a[0]=='G'){
			aa=atoi(a.substr(1,a.length()-1).c_str())+offset;
		}else{
			aa=atoi(a.c_str());
		}
		if(b[0]=='G'){
			bb=atoi(b.substr(1,b.length()-1).c_str())+offset;
		}else{
			bb=atoi(b.c_str());
		}
		Adj[aa].push_back(node(bb,dis));
		Adj[bb].push_back(node(aa,dis));
	}
	int ans=-1;
	double sum=0,minSum=0,dis=INF,ansDis=-1;//ansdis是最大的最近距离
	for(int i=1;i<=M;i++){
		int station=offset+i;
		sum=0;
		dis=INF;
		DJ(station);
		for(int j=1;j<=N;j++){
			if(d[j]>D){
				dis=-1;
				break;
			}
			if(d[j]<dis) dis=d[j];
			sum+=d[j];
		}
		if(dis==-1) continue;
		if(dis>ansDis){// 题意是先让加油站离每个城市尽可能远，也就是和所有城市之间的最小距离要最大
			ans=station;
			ansDis=dis;
			minSum=sum;
		}else if(dis==ansDis && sum<minSum){// 最大最小距离相同时考虑平均距离最小
			ans=station;
			minSum=sum;
		}
//		if(sum>maxSum){
//			maxSum=sum;
//			ans=station;
//			minDis=dis;
//		}else if(sum==maxSum && dis<minDis){
//			ans=station;
//			minDis=dis;
//		}
	}
	if(ans==-1) cout<<"No Solution"<<endl;
	else{
		printf("G%d\n%.1f %.1f\n",ans-offset,ansDis,minSum/N);
	}
	return 0;
}

