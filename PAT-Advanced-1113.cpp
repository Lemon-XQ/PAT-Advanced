#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int INF=0x3fffffff;

int main(){
	int N;
	cin>>N;
	int arr[N],sum1=0,sum2=0;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	} 
	sort(arr,arr+N);
	for(int i=0;i<N;i++){
		if(i<=N/2-1) sum1+=arr[i];
		else sum2+=arr[i];
	}
	if(N%2==0) cout<<"0 ";
	else cout<<"1 ";
	cout<<sum2-sum1<<endl;
	return 0;
}
