// LIS版
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N,M,L;
	cin>>N>>M;
	int order[201];
	fill(order,order+201,-1);
	for(int i=1;i<=M;i++){
		int num;
		cin>>num;
		order[num]=i;
	}
	cin>>L;
	int total[L+1],dp[L+1],ans=0;
	for(int i=1;i<=L;i++){
		cin>>total[i];
		total[i]=order[total[i]];// 把序列中的数映射成递增序列，其他数为-1
	}
	for(int i=1;i<=L;i++){
		dp[i]=1;// 初始化,dp[i]表示以total[i]为结尾的最大序列长度
		for(int j=1;j<i;j++){// 枚举从头到i
			// -1说明不是序列中的数
			if(total[i]!=-1 && total[j]!=-1 && total[j]<=total[i] && dp[j]+1>dp[i]){
			  dp[i]=dp[j]+1;
			}
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}

// LCS版
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main(){
//	int N,M,L;
//	cin>>N>>M;
//	int order[N+1];
//	for(int i=1;i<=M;i++) cin>>order[i];
//	cin>>L;
//	int total[L+1],dp[M+1][L+1];
//	for(int i=1;i<=L;i++) cin>>total[i];
//	fill(dp[0],dp[0]+M*L,0);
//	for(int i=1;i<=M;i++){
//		for(int j=1;j<=L;j++){
//			if(order[i]==total[j]){
//			  dp[i][j]=max(dp[i-1][j],dp[i][j-1])+1;
//				// if(total[j]==total[j-1]) dp[i][j]=dp[i][j-1]+1;
//				// else dp[i][j]=dp[i-1][j-1]+1;
//			}else{
//				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//			}
//		}
//	}
//	cout<<dp[M][L]<<endl;
//	return 0;
//}

