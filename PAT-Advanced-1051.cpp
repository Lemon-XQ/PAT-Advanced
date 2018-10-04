#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main(){
	int M,N,K;
	cin>>M>>N>>K;
	for(int i=0;i<K;i++){
		int num,index=1;
		bool flag=true;
		stack<int> s;
		for(int j=0;j<N;j++){
			cin>>num;
			if(flag){
				while(s.size()==0 || s.top()!=num){// push
					s.push(index++);
					if(s.size()>M){
						flag=false;
						break;
					}
				}
				if(flag && s.size()>=1 && s.top()==num) s.pop();
			}
		} 
		if(!flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
