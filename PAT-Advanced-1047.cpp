#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
	int N,K;
	cin>>N>>K;
	map<int,vector<string> > m;
	for(int i=0;i<N;i++){
		int num;
		string name;
		name.resize(4);
		scanf("%s %d",&name[0],&num);
		for(int j=0;j<num;j++){
			int index;
			scanf("%d",&index);
			m[index].push_back(name);
		}
	}
	for(int i=1;i<=K;i++){
		sort(m[i].begin(),m[i].end());
		printf("%d %d\n",i,m[i].size());
		for(int j=0;j<m[i].size();j++){
			printf("%s\n",m[i][j].c_str());
		}
	}
	return 0;
}
