#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
	int M,N,S;
	cin>>M>>N>>S;
	map<string,int> m;
	int offset=0;
	for(int i=1;i<=M;i++){
		string str;
		cin>>str;
		if(i==S+offset){
			if(m.count(str)==0){
				m[str]=1;
				offset+=N;
				cout<<str<<endl;
			}else{
				offset++;// ÖÐ¹ýµÄË³ÒÆ
			}
		}
	}
	if(S>M){
		cout<<"Keep going..."<<endl;
	}
	return 0;
}
