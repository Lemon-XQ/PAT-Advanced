#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin>>N;
	int arr[N],ans=0;
	for(int i=0;i<N;i++) cin>>arr[i];
	sort(arr,arr+N,greater<int>());
	int i;
	for(i=0;i<N;i++){
		if(i+1>=arr[i]) break;
	}
	if(arr[0]==0) cout<<0<<endl;
	else cout<<i<<endl;
	return 0;
}
