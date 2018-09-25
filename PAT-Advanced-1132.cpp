#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

const int MAXV=10001;
const int INF=0x3fffffff;

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		string num;
		cin>>num;
		int a=atoi(num.substr(0,num.length()/2).c_str());
		int b=atoi(num.substr(num.length()/2,num.length()-num.length()/2).c_str());
		int c=atoi(num.c_str());
		if(b!=0 && c%(a*b)==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
