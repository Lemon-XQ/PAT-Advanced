#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	string str;
	getline(cin,str);
	int dp[1001][1001]={0};
	int ans=1;// ×îÉÙÎª1
	for(int i=0;i<str.length();i++){
		dp[i][i]=1;
		if(i!=str.length()-1 && str[i]==str[i+1]) dp[i][i+1]=1;
	}
	for(int L=3;L<=str.length();L++){
		for(int i=0;i+L-1<str.length();i++){
			int j=i+L-1;
		// 	if(str[i]==str[j] && dp[i+1][j-1]==1){
		// 	  dp[i][j]=1;
		// 	 // ans=L;
		// 	}
			if(str[i]!=str[j]) dp[i][j]=0;
			else dp[i][j]=dp[i+1][j-1];
			if(dp[i][j]==1) ans=L;
		}
	}
	cout<<ans<<endl;
	return 0;
}

