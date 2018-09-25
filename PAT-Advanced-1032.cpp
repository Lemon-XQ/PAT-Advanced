#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXV=100001;

int main(){
	int a,b,N;
	cin>>a>>b>>N;
	int next[MAXV],next_a[MAXV];
	char data[MAXV];
	for(int i=0;i<N;i++){
		int addr,ne;
		char da;
		scanf("%d %c %d",&addr,&da,&ne);
		next[addr]=ne;
		data[addr]=da;
	}
	int value_a=a,value_b=b;
	while(value_a!=-1){
		next_a[value_a]=1;
		value_a=next[value_a];
	}
	bool flag=false;
	while(value_b!=-1){
		if(next_a[value_b]==1){
			printf("%05d\n",value_b);
			return 0;
		}
		value_b=next[value_b];
	}
	cout<<"-1"<<endl;
	return 0;
}
