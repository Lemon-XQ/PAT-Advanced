#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool isprime(int n){
	if(n<=1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}

int main(){
	int M,N;
	cin>>M>>N;
	while(!isprime(M)) M++;
	map<int,int> hash;
	vector<int> ans;
	for(int i=0;i<N;i++){
		int num,j;
		cin>>num;
		for(j=0;j<=M;j++){
			int value=(num+j*j)%M;
			if(hash.count(value)==0){
				ans.push_back(value);
				hash[value]=num;
				break;
			}
		}
		if(j==M+1) ans.push_back(-1);
	}
	for(int i=0;i<ans.size();i++){
		if(i!=0) cout<<" ";
		if(ans[i]==-1) cout<<"-";
		else cout<<ans[i];
	}
	return 0;
}
