#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
	int N,M;
	cin>>N;
	int arr[100000],arr2[100000];
	fill(arr,arr+100000,-1);
	fill(arr2,arr2+100000,-1);
	for(int i=0;i<N;i++){
		int a,b;
		cin>>a>>b;
		arr[a]=b;
		arr[b]=a;
	}
	cin>>M;
	set<int> ans;
	int g[M];
	for(int i=0;i<M;i++){
		cin>>g[i];
		arr2[g[i]]=1;
	}
	for(int i=0;i<M;i++){
		if(arr[g[i]]==-1 || arr2[arr[g[i]]]==-1) ans.insert(g[i]);
	}
	bool first=true;
	cout<<ans.size()<<endl;
	for(set<int>::iterator it=ans.begin();it!=ans.end();it++){
		if(!first) cout<<" ";
		printf("%05d",*it);
		first=false;
	}
	return 0;
}
