#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
	int N;
	cin>>N;
	map<int,int> m;
	for(int i=0;i<N;i++){
		string str;
		int count=0;
		cin>>str;
		for(int i=0;i<str.length();i++){
			count+=str[i]-'0';
		}
		m[count]++;
	}
	cout<<m.size()<<endl;
	bool first=true;
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
		if(!first) cout<<" ";
		first=false;
		cout<<it->first;
	}
	return 0;
}
