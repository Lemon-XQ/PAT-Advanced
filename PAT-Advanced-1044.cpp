#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV=100001;
int sum[MAXV]={0};
int BS(int left,int right,int x){// 二分查找防止超时
	while(left<right){
		int mid=(left+right)/2;
		if(sum[mid]>=x) right=mid;
		else left=mid+1;
	}
	return left;
}

int main(){
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];// 1到i的和
	} 
	int res=0,MIN=1001;
	bool flag=false;
	vector<pair<int,int> > ans;
	int left=1,right=N;
	for(int i=1;i<=N;i++){
		int j=BS(i,N,M+sum[i-1]);
		if(sum[j]-sum[i-1]<M) continue;
		if(sum[j]-sum[i-1]-M<MIN){
			ans.clear();
			ans.push_back(make_pair(i,j));
			MIN=sum[j]-sum[i-1]-M;
		}else if(sum[j]-sum[i-1]-M==MIN){
			ans.push_back(make_pair(i,j));
		}
	}
	for(int i=0;i<ans.size();i++){
		printf("%d-%d\n",ans[i].first,ans[i].second);
	}
	return 0;
}
