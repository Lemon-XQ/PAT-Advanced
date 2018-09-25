#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

const int INF=0x3fffffff;
const int MAXV=26*26*26;

struct node{
	int weight;
	int v;
	node(int _v,int _weight){
		v=_v; weight=_weight;
	}
};

vector<node> Adj[MAXV];
int N,K;
int d[MAXV],w[MAXV],happiness[MAXV],num[MAXV]={0};// d为第一标尺，w为第二标尺
bool visit[MAXV]={false};
vector<int> pre[MAXV];// pre[v]表示从起点到v的最短路径上v的前一个顶点
void DJ(int start){
	fill(d,d+MAXV,INF);
	fill(w,w+MAXV,0);
	fill(visit,visit+MAXV,false);
	d[start]=0;
	num[start]=1;
	w[start]=happiness[start];
	for(int i=0;i<N;i++){
		int u=-1, min=INF;
		for(int j=0;j<MAXV;j++){
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
					w[v]=w[u]+happiness[v];
					pre[v].clear();
					pre[v].push_back(u);
					num[v]=num[u];
				 }else if(d[u]+Adj[u][j].weight==d[v]){// 找到多条最短路径
					if(w[u]+happiness[v]>w[v]){// 第二标尺
						pre[v].push_back(u);
						w[v]=w[u]+happiness[v];
					}
					num[v]+=num[u];
				 }
			}
		}
	}
}

vector<int> tmpPath,path;
double maxAvg=0;
void dfs(int start,int v){
	if(v==start){
		tmpPath.push_back(start);
		double hap=w[tmpPath[0]]/(double)(tmpPath.size()-1);
		if(hap>maxAvg){
			maxAvg=hap;
			path=tmpPath;
		}
		tmpPath.pop_back();
		return;
	}
	for(int i=0;i<pre[v].size();i++){
		tmpPath.push_back(v);
		dfs(start,pre[v][i]);
		tmpPath.pop_back();
	}
}

int toInt(string str){
	return (str[0]-'A')*26*26+(str[1]-'A')*26+(str[2]-'A');
}

string toString(int num){
	string str;
	str.resize(3);
	str[0]='A'+num/(26*26);
	str[1]='A'+num%(26*26)/26;
	str[2]='A'+num%(26*26)%26;
	return str;
}

int main(){
	string start,des="ROM";
	cin>>N>>K>>start;
	for(int i=0;i<N-1;i++){
		string city;
		int h;
		cin>>city>>h;
		happiness[toInt(city)]=h;
	}
	for(int i=0;i<K;i++){
		string city1,city2;
		int cost;
		cin>>city1>>city2>>cost;
		Adj[toInt(city1)].push_back(node(toInt(city2),cost));
		Adj[toInt(city2)].push_back(node(toInt(city1),cost));
	}
	DJ(toInt(start));
	dfs(toInt(start),toInt(des));
	cout<<num[toInt(des)]<<" "<<d[toInt(des)]<<" "<<w[toInt(des)]<<" "<<(int)maxAvg<<endl;
	reverse(path.begin(),path.end());
	for(int i=0;i<path.size();i++){
		if(i!=0) cout<<"->";
		cout<<toString(path[i]);
	}
	return 0;
}

