#include <iostream>

using namespace std;

int main(){
	int N,ans=0;
	cin>>N;
	int arr[N+1];
	arr[0]=0;
	for(int i=1;i<=N;i++) cin>>arr[i];
	for(int i=0;i<N;i++){
		int dis=arr[i+1]-arr[i];
		if(dis>0) ans+=dis*6;// up
		else if(dis<0) ans+=-1*dis*4;// down
	}
	ans+=5*N;
	cout<<ans<<endl;
	return 0;
}
