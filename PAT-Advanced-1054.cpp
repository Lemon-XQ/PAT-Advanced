#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
	int N,M;
	cin>>M>>N;
	map<int,int> m;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int num;
			cin>>num;
			m[num]++;
		}
	}
	int MAX=0,ans;
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
		if(it->second>M*N/2 && it->second>MAX){
			ans=it->first;
			MAX=it->second;
		}
	}
	cout<<ans<<endl;
	return 0;
}
