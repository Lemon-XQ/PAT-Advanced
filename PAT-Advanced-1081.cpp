#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int gcd(int a, int b){
    return b==0?a:gcd(b, a%b);
}

int main(){
	int N;
	long long fenzi=0,fenmu=1;
	cin>>N;
	for(int i=0;i<N;i++){
		int a,b,g;
		scanf("%d/%d",&a,&b);
		g=gcd(b,a);
		a/=g; b/=g;
		g=gcd(b,fenmu);
		b/=g;
		fenzi=a*fenmu/g+fenzi*b;
		fenmu=b*fenmu;
	}
	int g=gcd(fenmu,fenzi);
	fenzi/=g;
	fenmu/=g;
	if(fenzi%fenmu==0) cout<<fenzi/fenmu<<endl;
	else if(fenzi/fenmu==0) cout<<fenzi<<"/"<<fenmu<<endl;
	else cout<<fenzi/fenmu<<" "<<fenzi%fenmu<<"/"<<fenmu<<endl;
	return 0;
}
