#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV=501;

int N,M,cnt=0;
vector<int> Adj[MAXV];
bool visit[MAXV]={false};
void dfs(int index){
	visit[index]=true;
	cnt++;
	for(int i=0;i<Adj[index].size();i++){
		if(visit[Adj[index][i]]==false) dfs(Adj[index][i]);
	}
	return;
}

int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	int odd=0;// 奇数结点
	bool flag=true,connect=true;
	for(int i=1;i<=N;i++){
		if(i!=1) cout<<" ";
		cout<<Adj[i].size();
		if(Adj[i].size()%2==1) odd++;
	}
	// 判断连通性
	dfs(1);
	cout<<endl;
	if(odd==0 && cnt==N) cout<<"Eulerian"<<endl;
	else if(odd==2 && cnt==N) cout<<"Semi-Eulerian"<<endl;
	else cout<<"Non-Eulerian"<<endl;
	return 0;
}
