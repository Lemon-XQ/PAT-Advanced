#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAXN=1001;

bool isPrime(int x){
	if(x<2) return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}

int main(){
	int N,K,num;
	cin>>N;
	int arr[N];
	map<int,int> m;
	for(int i=0;i<N;i++){
		cin>>num;
		m[num]=i+1;
	}
	cin>>K;
	bool checked[10001]={false};
	for(int i=0;i<K;i++){
		int query;
		cin>>query;
		if(m.count(query)==0) printf("%04d: Are you kidding?\n",query);
		else if(checked[query]) printf("%04d: Checked\n",query);
		else if(m[query]==1) printf("%04d: Mystery Award\n",query);
		else if(isPrime(m[query])) printf("%04d: Minion\n",query);
		else printf("%04d: Chocolate\n",query);
		if(m.count(query)!=0) checked[query]=true;
	}
	return 0;
}
