#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool isprime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}

int main(){
	int size,N,M,n;
	cin>>size>>N>>M;
	for(n=size;;n++){
		if(isprime(n)) break;
	}
	size=n;// prime
	int key;
	map<int,int> hash,time;
	for(int i=0;i<N;i++){
		int num;
		cin>>num;
		int j;
		for(j=0;j<=size;j++){
			int value=(num+j*j)%size;
			time[num]++;
			if(hash.count(value)==0){
				hash[value]=num;
				break;
			}
		}
		if(j==size+1) printf("%d cannot be inserted.\n",num);
	} 
	int total=0;
	for(int i=0;i<M;i++){
		cin>>key;
		if(time.count(key)!=0) total+=time[key];
		else{
			for(int j=0;j<=size;j++){
				int value=(key+j*j)%size;
				total++;
				if(hash.count(value)==0){
					break;
				}
			}
		}
	} 
	cout<<total<<endl;
	printf("%.1lf\n",total/(double)M);
	return 0;
}
