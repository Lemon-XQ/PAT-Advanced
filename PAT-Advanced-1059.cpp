#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	long long N;
	cin>>N;
	cout<<N<<"=";
	long long res=1;
	bool first=true;
    for(long long i=2;i*i<=N;i++){
        long long k=0;
        while(N%i == 0){
            N=N/i;
            k++;
        }
        if(k!=0 && !first) cout<<"*";
		if(k!=0) first=false;
        if(k!=0 && k!=1)  cout<<i<<"^"<<k;
		else if(k==1) cout<<i;
        if(k!=0) res*=pow(i,k);
    }
    if(!first && N!=1) cout<<"*"<<N;
	if(first) cout<<N;
	return 0;
}
