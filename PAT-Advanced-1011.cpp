#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double W[3],T[3],L[3],max_profit=1;
	string ans="";
	for(int i=0;i<3;i++){
		cin>>W[i]>>T[i]>>L[i];
		if(W[i]>max(T[i],L[i])){
			ans+="W";
			max_profit*=W[i];
		} 
		if(T[i]>max(W[i],L[i])){
			ans+="T";
			max_profit*=T[i];
		} 
		if(L[i]>max(W[i],T[i])){
			ans+="L";
			max_profit*=L[i];
		} 
		ans+=" ";
	} 
	max_profit=(max_profit*0.65-1.0)*2.0;
	cout<<ans;
	printf("%.2lf",max_profit);
	return 0;
}

