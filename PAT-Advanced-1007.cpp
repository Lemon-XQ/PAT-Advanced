#include <iostream>
#include <algorithm>

using namespace std;

const int INF=0x3fffffff;

int main(){
	int K;
	cin>>K;
	int arr[K],dp[K];
	bool flag=false;
	for(int i=0;i<K;i++){
		cin>>arr[i];
		if(arr[i]>=0) flag=true;
		dp[i]=0;
	} 
	if(!flag) cout<<0<<" "<<arr[0]<<" "<<arr[K-1]<<endl;
	else{
		dp[0]=arr[0];
		int ans=arr[0],first=0,last=0;// 注意ans的初始值不能为-INF
		int s[K];// 记录首元素位置
		fill(s,s+K,0);
		for(int i=1;i<K;i++){
			if(dp[i-1]+arr[i]>arr[i]) s[i]=s[i-1];
			else s[i]=i;
			dp[i]=max(dp[i-1]+arr[i],arr[i]);
			if(dp[i]>ans){
				ans=dp[i];
				last=i;
			} 
		}
//		int tmp=0;
//		for(int i=last;i>=0;i--){
//			tmp+=arr[i];
//			if(tmp==ans){
//				first=i;
//			}
//		}
		cout<<ans<<" "<<arr[s[last]]<<" "<<arr[last]<<endl;
	}
	return 0;
}

