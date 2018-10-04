#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
	long long N,max=0,ans=0;
	cin>>N;
	for(long long i=2;i*i<=N;i++){
		long long num=N,cnt=-1,j=i,tmp=1;
		while(num%tmp==0){
			cnt++;
			tmp*=j;
			j++;
		}
		if(cnt>max){
			max=cnt;
			ans=i;
		}
	}
	if(max==0) printf("1\n%ld\n",N);
	else{
		printf("%ld\n",max);
		for(int i=0;i<max;i++){
			if(i!=0) printf("*");
			printf("%ld",ans+i);
		}
	}
	return 0;
}
