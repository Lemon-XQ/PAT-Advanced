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
		// 正溢出
		if(res<0 && a>0 && b>0) ans="true";
		// 负溢出
		else if(res>=0 && a<0 && b<0) ans="false";
		// 正常
		else if(res>c) ans="true";
		else if(res<=c) ans="false";
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}

