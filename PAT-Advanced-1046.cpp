#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	int D[N],total=0;
	for(int i=0;i<N;i++){
		scanf("%d",&D[i]);
		total+=D[i];
	}
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a>b) swap(a,b);
		int dis_1=0,dis_2=0;
		for(int j=a-1;j<b-1;j++) dis_1+=D[j];
		dis_2=total-dis_1;
		printf("%d\n",min(dis_1,dis_2));
	}
	return 0;
}

