#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		long long a,b,c;
		string ans;
		cin>>a>>b>>c;
		long long res=a+b;
		// �����
		if(res<0 && a>0 && b>0) ans="true";
		// �����
		else if(res>=0 && a<0 && b<0) ans="false";
		// ����
		else if(res>c) ans="true";
		else if(res<=c) ans="false";
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}
