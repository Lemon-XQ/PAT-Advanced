#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int father[1001];
// 返回元素x所在集合的根结点
int findFather(int x){
	while(x != father[x]){
		x=father[x];
	}
	return x;
}

void Union(int a,int b){
	int f_a = findFather(a);
	int f_b = findFather(b);
	if(f_a!=f_b) father[f_a]=f_b;
}

bool hasCommon(vector<int> a,vector<int> b){
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			if(a[i]==b[j]) return true;
		}
	}
	return false;
}

int main(){
	int N;
	cin>>N;
	vector<vector<int> > v;
	v.resize(N+1);
	for(int i=1;i<=N;i++){
		int K;
        scanf("%d:",&K);
        for(int j=0;j<K;j++){
        	int num;
        	cin>>num;
        	v[i].push_back(num);
		}
	} 
	for(int i=1;i<=N;i++){
		father[i]=i;
	}
	int isRoot[N+1],count=0;
	fill(isRoot,isRoot+N+1,0);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i!=j && hasCommon(v[i],v[j])){// 爱好有共同则生成一条关系
				Union(i,j);// 合并关系两头的两个人
			}
		}
	}
	for(int i=1;i<=N;i++){
		isRoot[findFather(i)]++;
	}
	sort(isRoot,isRoot+N+1,greater<int>());
	for(int i=0;i<N+1;i++){
		if(isRoot[i]!=0) count++;
	}
	cout<<count<<endl;
	for(int i=0;i<count;i++){
		if(i!=0) cout<<" ";
		cout<<isRoot[i];
	}
	return 0;
}

