#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
	int N;
	cin>>N;
	int arr[N];
	double len=0;
	for(int i=0;i<N;i++) cin>>arr[i];
	sort(arr,arr+N);// 从小到大逐个合并就是最优解
	for(int i=0;i<N-1;i++){
    	len=(arr[i]+arr[i+1])/2.0;
    	arr[i+1]=len;
    }
    cout<<(int)len<<endl;
	return 0;
}
