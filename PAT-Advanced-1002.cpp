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
		// ��������ˡ��������ֻҪָ����ͬ��ֱ�ӽ�������Ӿ���= = 
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
	// �ҷ���������� 
	for(int i=1000;i>=0;i--){
		if(arr[i]!=0) count++;
	}
	if(count==0) cout<<0<<endl;// ע��Ϊ0��������� 
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