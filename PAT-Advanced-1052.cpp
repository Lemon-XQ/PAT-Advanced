#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
	int N,head;
	cin>>N>>head;
	int next[100000],data[100000],tmp[100000];
	map<int,int> m;
	for(int i=0;i<N;i++){
		int addr,key;
		cin>>addr;
		cin>>tmp[addr]>>next[addr];
		m[tmp[addr]]=addr;
	}
	int cnt=0;
	while(head!=-1){// 注意去除不在一条链上的无效结点
		data[cnt++]=tmp[head];
		head=next[head];
	}
	if(cnt==0){// 没有有效结点
		cout<<"0 -1";
		return 0;
	}
	sort(data,data+cnt);
	head=m[data[0]];
	printf("%d %05d\n",cnt,head);
	int index=1;
	while(cnt--!=0){
		if(cnt==0) printf("%05d %d -1\n",head,data[index-1]);
		else printf("%05d %d %05d\n",head,data[index-1],m[data[index]]);
		head=m[data[index++]];
	}
	return 0;
}
