#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int main(){
	int K;
	cin>>K;
	for(int i=0;i<K;i++){
		int N;
		cin>>N;
		int arr[N];
		set<int> s;
		for(int j=0;j<N;j++){
			cin>>arr[j];
			s.insert(arr[j]);
		}
		if(s.size()!=N) cout<<"NO"<<endl;
		else{
			int j;
			bool flag=true;
			for(j=0;j<N-1;j++){
				for(int k=0;k<j;k++)
					if(abs(arr[j]-arr[k])==abs(j-k)) flag=false;
				if(!flag) break;
			}
			if(j!=N-1) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
	return 0;
}
