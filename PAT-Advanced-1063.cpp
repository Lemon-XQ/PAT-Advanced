#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
	int N,K;
	cin>>N;
	set<int> s[51];
	for(int i=0;i<N;i++){
		int M,num;
		cin>>M;
		for(int j=0;j<M;j++){
			cin>>num;
			s[i+1].insert(num);
		}
	}
	cin>>K;
	for(int i=0;i<K;i++){
		int a,b;
		cin>>a>>b;
		vector<int> bing,jiao;
    	set_union(s[a].begin(),s[a].end(),s[b].begin(),s[b].end(),inserter(bing,bing.begin()));
    	set_intersection(s[a].begin(),s[a].end(),s[b].begin(),s[b].end(),inserter(jiao,jiao.begin()));
    	printf("%.1lf%\n",jiao.size()*100/(double)bing.size());
	}
	return 0;
}
