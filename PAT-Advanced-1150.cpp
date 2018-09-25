#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int INF=0x3fffffff;
const int MAXV=201;
int G[MAXV][MAXV];

int main(){
	int N,M,K;
	cin>>N>>M;
	fill(G[0],G[0]+MAXV*MAXV,-1);
	for(int i=0;i<M;i++){
		int a,b,dis;
		cin>>a>>b>>dis;
		G[a][b]=G[b][a]=dis;
	}
	cin>>K;
	int ans_index,ans_len=INF;
	for(int i=1;i<=K;i++){
		int n;
		cin>>n;
		int path[n],len=0;
		bool flag=true;
		set<int> s;
		for(int j=0;j<n;j++){
			cin>>path[j];
			s.insert(path[j]);
		}
		for(int j=0;j<n-1;j++){
			if(G[path[j]][path[j+1]]==-1){
				flag=false;// 说明所给路径不连通
				break;
			}else len+=G[path[j]][path[j+1]];// 路径总长度
		}
		if(flag){
			if(s.size()!=N || path[0]!=path[n-1]){
				printf("Path %d: %d (Not a TS cycle)\n",i,len);
			}else{
				if(len<ans_len){// TS cycle 记录最短路径长度及路径编号
					ans_len=len;
					ans_index=i;
				}
				if(s.size()==n-1) printf("Path %d: %d (TS simple cycle)\n",i,len);
				else printf("Path %d: %d (TS cycle)\n",i,len);
			}
		}
		else printf("Path %d: NA (Not a TS cycle)\n",i);
	}
	printf("Shortest Dist(%d) = %d",ans_index,ans_len);
	return 0;
}
