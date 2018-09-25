#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=10001;
int father[MAXN];

void init(){
	for(int i=0;i<MAXN;i++) father[i]=i;
}

int findFather(int x){
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	while(a!=father[a]){
		int z=a;
  		a=father[a];
		father[z]=x;
	}
	return x;
}

void Union(int a,int b){
    int fa=findFather(a);
    int fb=findFather(b);
    if(fa!=fb) father[fa]=fb;
}

int main(){
	init();
	int N,Q;
	bool visit[MAXN]={false};
	cin>>N;
	for(int i=0;i<N;i++){
		int K,a[MAXN];
		cin>>K;
		for(int i=0;i<K;i++){
			cin>>a[i];
			visit[a[i]]=true;
			Union(a[0],a[i]);
		}
	}
	int isRoot[MAXN]={0},count=0,total=0;
	for(int i=0;i<MAXN;i++){
		if(visit[i]) isRoot[findFather(i)]++;
	}
	for(int i=0;i<MAXN;i++){
		if(isRoot[i]!=0){
			count++;
			total+=isRoot[i];
		} 
	}
	cout<<count<<" "<<total<<endl;
	cin>>Q;
	for(int i=0;i<Q;i++){
		int a,b;
		cin>>a>>b;
		if(findFather(a)==findFather(b)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
