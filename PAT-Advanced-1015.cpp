#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

bool isPrime(int num){
  if(num<2) return false;
	for(int i=2;i*i<=num;i++){
		if(num%i==0) return false;
	}
	return true;
}

int main(){
	int N,D;
	while(cin>>N && N>=0){
		cin>>D;
		if(!isPrime(N)){
			cout<<"No"<<endl;
		}else{
			int arr[100]={0},len=0;
			while(N/D!=0){
				arr[len++]=N%D;
				N=N/D;
			}
			if(N!=0) arr[len]=N;
			int factor=0,sum=0;
			for(int i=len;i>=0;i--){
				sum+=(arr[i])*pow(D,factor++);
			}
			if(isPrime(sum)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}
