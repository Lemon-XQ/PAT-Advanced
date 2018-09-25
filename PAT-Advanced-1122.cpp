#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV=210;

int main(){
	int N,M,K;
	cin>>N>>M;
	int G[MAXV][MAXV]={0};
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		G[a][b]=1;
		G[b][a]=1;
	}
	cin>>K;
	for(int i=0;i<K;i++){
		vector<int> v;
		int visit[MAXV]={0};
		int M,num;
		cin>>M;
		for(int i=0;i<M;i++){
			cin>>num;
			visit[num]++;
			v.push_back(num);
		}
		// hamiton≈–∂œ
		if(M!=N+1 || v[0]!=v[v.size()-1]) cout<<"NO"<<endl;
		else{
			int j;
			for(j=1;j<N;j++){
				if(visit[v[j]]!=1)  break;
			}
			if(j!=N+1) cout<<"NO"<<endl;
			else{
				for(j=0;j<=N-1;j++){
					if(G[v[j]][v[j+1]]==0) break;
				}
				if(j!=N) cout<<"NO"<<endl;
				else cout<<"YES"<<endl;
			}
		}
	}
	return 0;
}
