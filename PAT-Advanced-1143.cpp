#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main(){
	int M,N;
	cin>>M>>N;
	set<int> s;
	int pre[N];
	map<int,int> pos;
	for(int i=0;i<N;i++){
		cin>>pre[i];
		s.insert(pre[i]);
	}
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
		if(s.count(u)==0 && s.count(v)!=0) printf("ERROR: %d is not found.\n",u);
		else if(s.count(v)==0 && s.count(u)!=0) printf("ERROR: %d is not found.\n",v);
		else if(s.count(v)==0 && s.count(u)==0) printf("ERROR: %d and %d are not found.\n",u,v);
		else{
			int _u=max(u,v);
			int _v=min(u,v);
			int j;
			// 遍历先序序列，找第一个在u和v之间的数（不用建树，dfs,会超时。。）
			for(j=0;j<N;j++){
				if(pre[j]>_v && pre[j]<_u || pre[j]==v || pre[j]==u) break;
			}
			if(pre[j]==v || pre[j]==u) printf("%d is an ancestor of %d.\n",pre[j],(pre[j]==u)?v:u);
			else printf("LCA of %d and %d is %d.\n",u,v,pre[j]);
		}
	}
	return 0;
}
