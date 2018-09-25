#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
	string s[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	string N;
	cin>>N;
	int count=0;
	for(int i=0;i<N.length();i++) count+=N[i]-'0';
	stringstream ss;
	ss<<count;
	N=ss.str();
	for(int i=0;i<N.length();i++){
		cout<<s[N[i]-'0'];
		if(i!=N.length()-1) cout<<" ";
	}
	return 0;
}

