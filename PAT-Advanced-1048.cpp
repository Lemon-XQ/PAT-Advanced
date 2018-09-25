#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    int arr[1001]={0};// 注意不能分配501，不然测试点3过不去（因为M的最大值为1000）
    for(int i=0;i<N;i++){
    	int num;
    	scanf("%d",&num);
    	arr[num]++;
	}
	bool flag=false;
	for(int i=1;i<=M/2;i++){
		if(arr[i]!=0 && arr[M-i]!=0 && M-i!=i || M-i==i && arr[i]>1){
			flag=true;
			cout<<i<<" "<<M-i<<endl;
			break;
		}
	}
	if(!flag) cout<<"No Solution"<<endl;
	return 0;
}

