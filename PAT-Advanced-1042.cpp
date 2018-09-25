#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(){
	int K;
	cin>>K;
	int order[55];
	vector<string> pai;
	stringstream ss;
	for(int i=0;i<4;i++){
//		ss.str("");
//		if(i==0) ss<<"S"; if(i==1) ss<<"H"; if(i==2) ss<<"C"; if(i==3) ss<<"D";
		for(int j=1;j<=13;j++){
			ss.str("");
			if(i==0) ss<<"S"; if(i==1) ss<<"H"; if(i==2) ss<<"C"; if(i==3) ss<<"D";
			ss<<j;
			pai.push_back(ss.str());
		}
	}
	ss.str("");
	ss<<"J"; ss<<1;
	pai.push_back(ss.str());
	ss.str("");
	ss<<"J"; ss<<2;
	pai.push_back(ss.str());
	
	for(int i=1;i<=54;i++) cin>>order[i];
	vector<string> ans;
	ans.resize(54);// 非常重要！！一定要初始化
	for(int i=0;i<K;i++){
		for(int j=1;j<=54;j++){
			ans[order[j]-1]=pai[j-1];
		}
		pai=ans;
	}
	for(int i=0;i<54;i++){
		cout<<pai[i];
		if(i!=53) cout<<" ";
	}
	return 0;
}





