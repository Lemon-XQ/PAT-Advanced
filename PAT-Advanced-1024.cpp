#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

bool check(string num){
	for(int i=0;i<num.length()/2;i++){
		if(num[i]!=num[num.length()-i-1]) return false;
	}
	return true;
}

int main(){
	int K,step=0;
	string N;
	cin>>N>>K;
	while(step<K){
		if(check(N)) break;
		string re=N;
		reverse(re.begin(),re.end());
		int offset=0;
		for(int i=N.length()-1;i>=0;i--){
			int tmp=re[i]-'0'+N[i]-'0'+offset;
			offset=tmp/10;
			N[i]=tmp%10+'0';
		}
		if(offset!=0) N.insert(0,1,offset+'0');
		step++;
	}
	cout<<N<<endl<<step<<endl;
	return 0;
}

