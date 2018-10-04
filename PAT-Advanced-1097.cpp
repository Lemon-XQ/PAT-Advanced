#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
	int head,N;
	cin>>head>>N;
	int next[100000],data[100000];
	map<int,int> m;
	for(int i=0;i<N;i++){
		int addr,num;
		cin>>addr;
		cin>>data[addr]>>next[addr];
	}
	vector<vector<int> > v;
	v.resize(2);// v[0]存储最后的序列，v[1]存储remove的序列
	while(head!=-1){
		if(m.count(data[head])==0 && m.count(-1*data[head])==0){
			v[0].push_back(head);
			m[data[head]]++;
		}else{
			v[1].push_back(head);
		}
		head=next[head];
	}
	for(int i=0;i<min(N,2);i++){
		int j;
		for(j=0;j<v[i].size()-1;j++){
			printf("%05d %d %05d\n",v[i][j],data[v[i][j]],v[i][j+1]);
		}
		printf("%05d %d -1\n",v[i][j],data[v[i][j]]);
	}
	return 0;
}
