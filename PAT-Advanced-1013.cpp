#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> Adj[1001];
bool visit[1001];
int city;
void dfs(int index){
	visit[index]=true;
	for(int i=0;i<Adj[index].size();i++){
		// ȥ��ɾ���Ľ���Լ����ʹ��Ľ��
		if(Adj[index][i]!=city && visit[Adj[index][i]]==false) dfs(Adj[index][i]);
	}
}

int main(){
	int N,M,K;
	cin>>N>>M>>K;
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	for(int i=0;i<K;i++){
		int count=0;
		fill(visit,visit+N+1,false);
		scanf("%d",&city);
		// ����ͨ����
		for(int i=1;i<=N;i++){
			if(i!=city && visit[i]==false){
				dfs(i);
				count++;
			}
//			if(i!=city && Adj[i].size()==0 || Adj[i].size()==1&&Adj[i][0]==city) count++;
		}
		cout<<count-1<<endl;
	}
	return 0;
}
