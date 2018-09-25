#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    string N1,N2,r;
    int tag;
    cin>>N1>>N2>>tag>>r;
	if(tag==2) swap(N1,N2);// 确保n2是待求进制数
    long long arr_1[10]={0},arr_2[10]={0},radix;
    long long max_n1=0,max_n2=0;
	if(isalpha(r[0])) radix=r[0]-'a'+10;
	else radix=atoi(r.c_str());
    for(int i=0;i<N1.length();i++){
    	if(isalpha(N1[i])) arr_1[i]=N1[i]-'a'+10;
    	else arr_1[i]=N1[i]-'0';
    	if(arr_1[i]>max_n1) max_n1=arr_1[i];
	}
	for(int i=0;i<N2.length();i++){
    	if(isalpha(N2[i])) arr_2[i]=N2[i]-'a'+10;
    	else arr_2[i]=N2[i]-'0';
    	if(arr_2[i]>max_n2) max_n2=arr_2[i];
	}
    bool flag=false;
	long long n1=arr_1[N1.length()-1];// 最低位*1，后面不断乘以radix的幂次
	long long factor=radix;
	for(int i=N1.length()-2;i>=0;i--){
		n1+=arr_1[i]*factor;
		factor*=radix;
	}
	long long low=max_n2+1,high=max(max_n2+1,n1)+1,ans=high;
	// 下界是最大的数字+1 上界是下界和n1的最大值+1
	// radix最大值不是36，只是数字的最大值是z，事实上radix为long long
//	for(ans=max_n2+1;ans<=max(max_n2+1,n1)+1;ans++){
	// 枚举第7个测试点会超时，改为二分查找，存储最小的满足题意的进制
	while(low<=high){
		long long mid=(low+high)/2;
		long long n2=arr_2[N2.length()-1];
		factor=mid;
		for(int i=N2.length()-2;i>=0;i--){
    		n2+=arr_2[i]*factor;
    		if(n2>n1 || n2<0) break;
    		factor*=mid;
		}
		if(n2==n1){
			flag=true;
			if(mid<ans) ans=mid;
			high=mid-1;
//			cout<<ans<<endl;
//			break;
		}else if(n2>n1 || n2<0){// 注意溢出的情况
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	if(!flag) cout<<"Impossible"<<endl;
	else cout<<ans<<endl;
	return 0;
}

