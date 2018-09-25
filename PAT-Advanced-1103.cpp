#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N,K,P;
vector<int> fac;// 存储不大于N的i的P次幂
vector<int> ans;// 存放最优的底数序列
vector<int> tmp;// 当前选中的底数组成的临时序列
int maxFacSum=-1;
// index表示选了fac第几个，nowK表示已经选了几个，sum表示选的数之和，facSum为选出的底数之和
void dfs(int index,int nowK,int sum,int facSum){
	if(nowK==K && sum==N){
		if(facSum>maxFacSum){// 底数之和更优
			maxFacSum=facSum;
			ans=tmp;
		}
		return;
	}
	if(sum>N || nowK>K) return;// 找不到答案
	if(index-1>=0){
		tmp.push_back(index);
		dfs(index,nowK+1,sum+fac[index],facSum+index);// 选
		tmp.pop_back();
		dfs(index-1,nowK,sum,facSum);// 不选
	}
}

int main(){
    cin>>N>>K>>P;
    for(int i=0;pow(i,P)<=N;i++) fac.push_back(pow(i,P));
	dfs(fac.size()-1,0,0,0);
	if(maxFacSum==-1) cout<<"Impossible"<<endl;
	else{
		cout<<N<<" = "<<ans[0]<<"^"<<P;
		for(int i=1;i<ans.size();i++) cout<<" + "<<ans[i]<<"^"<<P;
	}
	return 0;
}

