#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
	string N;
	cin>>N;
	int N1=0,N2=0;
	string ans=N;
	while(N1-N2!=6174){
		int len=4-ans.length();
		for(int i=0;i<len;i++) ans+="0";
		sort(ans.begin(), ans.end(),greater<char>());
		N1=atoi(ans.c_str());
		sort(ans.begin(), ans.end());
		N2=atoi(ans.c_str());
		stringstream ss;
		ss<<N1-N2;
		ans=ss.str();
		printf("%04d - %04d = %04d\n",N1,N2,N1-N2);
		if(N1==N2) break;// 0000µÄÇé¿ö
	}
}
