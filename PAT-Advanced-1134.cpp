#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

const int MAXV=10001;
const int INF=0x3fffffff;

int main(){
	int N,M,K;
	cin>>N>>M;
	vector<int> Adj[MAXV];
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	cin>>K;
	for(int i=0;i<K;i++){
		int nv;
		cin>>nv;
		set<pair<int,int> > edges;// 存储所有边
		for(int j=0;j<nv;j++){
			int v;
			scanf("%d",&v);
			for(int k=0;k<Adj[v].size();k++){
				edges.insert(make_pair(v,Adj[v][k]));
				edges.insert(make_pair(Adj[v][k],v));
			}
		}
		// 无向边，所以要*2
		if(edges.size()==M*2) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
