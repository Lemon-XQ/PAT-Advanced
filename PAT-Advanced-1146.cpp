#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

const int MAXV=1001;
int inDegree[MAXV]={0},outDegree[MAXV]={0};
vector<int> Adj[MAXV];
int N,M,K;

vector<int> path;
int cnt[MAXV]={0};
int index=0;
void topoOrder(){
	queue<int> q;
	for(int i=1;i<=N;i++){
		if(inDegree[i]==0){
			q.push(i);
			cnt[index]++;
		}
	}
	index++;
	while(!q.empty()){
		int v=q.front();
		q.pop();
		path.push_back(v);
		for(int i=0;i<Adj[v].size();i++){
			inDegree[Adj[v][i]]--;
			if(inDegree[Adj[v][i]]==0){
				q.push(Adj[v][i]);
				cnt[index]++;
			}
		}
		if(cnt[index]>0) index++;
	}
}

int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		Adj[a].push_back(b);
		inDegree[b]++;
		outDegree[a]++;
	}
//	topoOrder();
	cin>>K;
	vector<int> ans;
	int in[MAXV];
	for(int i=0;i<K;i++){
  		copy(inDegree,inDegree+N+1,in);
		vector<int> query;
		for(int j=0;j<N;j++){
			int num;
			cin>>num;
			query.push_back(num);
		}
		for(int j=0;j<query.size();j++){
			if(in[query[j]]!=0){
				ans.push_back(i);
				break;
			}else{
				for(int k=0;k<Adj[query[j]].size();k++) in[Adj[query[j]][k]]--;
			}
		}
//		if(inDegree[query[0]]!=0 || outDegree[query[N-1]]!=0) ans.push_back(i);
//		else{
//			if(query==path) continue;
//			int offset=0;
//			for(int j=0;j<index;j++){
//				set<int> s;
//				for(int k=0;k<cnt[j];k++){
//					s.insert(query[k+offset]);
//					s.insert(path[k+offset]);
//				}
//				if(s.size()!=cnt[j]){
//					ans.push_back(i);
//					break;
//				}
//				offset+=cnt[j];
//			}
//		}
	}
	for(int i=0;i<ans.size();i++){
		if(i!=0) cout<<" ";
		cout<<ans[i];
	}
	return 0;
}
