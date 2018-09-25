#include <iostream>

using namespace std;

int main(){ 
	int K;
	cin>>K;
	double arr[1001]={0};
	for(int i=0;i<K;i++){
		int N;
		cin>>N;
		cin>>arr[N];
	}
	cin>>K;
	int count=0;
	for(int i=0;i<K;i++){
		int N;
		double a;
		cin>>N>>a;
		// 是我想多了……这道题只要指数相同，直接将底数相加就行= = 
		/*if(arr[N]==0){
			count++;	
			arr[N]+=a;
		} 
		else{
			if(N==1 || N==0) arr[N]+=a;
			else{
				double d=pow(arr[N],N)+pow(a,N);
				//cout<<d<<endl;
				arr[N]=pow(d,1.0/N);	
			}
		}*/
	}
	// 找非零项的数量 
	for(int i=1000;i>=0;i--){
		if(arr[i]!=0) count++;
	}
	if(count==0) cout<<0<<endl;// 注意为0的特殊情况 
	else{
		cout<<count<<" ";
		bool flag=false;
		for(int i=1000;i>=0;i--){
			if(arr[i]!=0){
				if(flag) cout<<" ";
				cout<<i<<" ";
				printf("%.1lf",arr[i]);
				flag=true;
			}
		}
	}
	
}