#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

const int MAXV=100001;
const int INF=0x3fffffff;

int main(){
	int start,N,K;
	cin>>start>>N>>K;
	int next[MAXV],data[MAXV];
	for(int i=0;i<N;i++){
		int addr,da,ne;
		cin>>addr>>da>>ne;
		next[addr]=ne;
		data[addr]=da;
	}
	int current=start;
	vector<int> ans;
	while(current!=-1){
		if(data[current]<0) ans.push_back(current);
		current=next[current];
	}
	current=start;
	while(current!=-1){
		if(data[current]>=0 && data[current]<=K) ans.push_back(current);
		current=next[current];
	}
	current=start;
	while(current!=-1){
		if(data[current]>K) ans.push_back(current);
		current=next[current];
	}
	for(int i=0;i<ans.size()-1;i++){
		printf("%05d %d %05d\n",ans[i],data[ans[i]],ans[i+1]);
	}
	printf("%05d %d -1\n",ans[ans.size()-1],data[ans[ans.size()-1]]);
	return 0;
}
