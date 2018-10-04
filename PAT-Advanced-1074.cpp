#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N,K;
    int first;
    cin>>first>>N>>K;
    int data[100000],next[100000],arr[100000];
    for(int i=0;i<N;i++){
    	int j;
    	cin>>j;
		cin>>data[j]>>next[j];
    }
    //for(int i=0;i<N;i++){
    //	arr[i]=first;
    //	first=next[first];
    //}
    N=0;
    while(first!=-1){
        arr[N++]=first;
        first=next[first];
    }
    int len=N/K;
    for(int i=0;i<len;i++){
    	reverse(arr+i*K,arr+i*K+K);
    }
    for(int i=0;i<N-1;i++){
    	printf("%05d %d %05d\n",arr[i],data[arr[i]],arr[i+1]);
    }
    printf("%05d %d %d",arr[N-1],data[arr[N-1]],-1);
}
