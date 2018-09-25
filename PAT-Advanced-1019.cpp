#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int N,b;
	cin>>N>>b;
  bool flag=false;
	vector<int> v;
	stringstream ss;
	while(N/b){
		v.push_back(N%b);// 考虑到有可能有两位数出现，不用str存储
		N=N/b;
	}
	v.push_back(N);
	vector<int> tmp=v;
	reverse(v.begin(),v.end());
	if(tmp==v) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i];
		if(i!=v.size()-1) cout<<" ";
	}
	return 0;
}

