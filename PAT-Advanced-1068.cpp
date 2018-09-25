#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	int coin[10010],dp[110]={0};// dp[i]表示钱为i时能筹到的钱
	for(int i=1;i<=N;i++) cin>>coin[i];
	sort(coin+1,coin+N+1,greater<int>());// 从大到小（因为优先字典序小的）
	bool choice[10010][110]={false};
	for(int i=1;i<=N;i++){
		for(int j=M;j>=coin[i];j--){
			if(dp[j]>dp[j-coin[i]]+coin[i]) choice[i][j]=0;// 不放
			else{
				choice[i][j]=1;// 放
				dp[j]=dp[j-coin[i]]+coin[i];
			}
			cout<<i<<" "<<j<<" "<<dp[j]<<" "<<choice[i][j]<<endl;
		}
	}
	if(dp[M]!=M) cout<<"No Solution"<<endl;
	else{
		bool first=true;
		int v=M;
		for(int i=N;i>=1;i--){
			if(choice[i][v]==1){// 钱为v时需要选中哪件物品
				if(!first) cout<<" ";
				cout<<coin[i];
				v-=coin[i];
				first=false;
			}
		}
	}
	return 0;
}

