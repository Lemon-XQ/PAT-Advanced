#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
	int N,K;
	cin>>N>>K;
	map<string,vector<int> > m;
	for(int i=0;i<K;i++){
		int index,num;
		cin>>index>>num;
		for(int j=0;j<num;j++){
			string str;
			cin>>str;
			m[str].push_back(index);
		}
	}
	for(int i=0;i<N;i++){
		string name;
		cin>>name;
		cout<<name<<" "<<m[name].size();
		sort(m[name].begin(),m[name].end());
		for(int j=0;j<m[name].size();j++){
			cout<<" "<<m[name][j];
		}
		cout<<endl;
	}
	return 0;
}
