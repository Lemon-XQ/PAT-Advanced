#include <iostream>

using namespace std;

int main(){
	int K1,K2;
	cin>>K1;
	double a[1001]={0},b[1001]={0},c[2002]={0};
	for(int i=0;i<K1;i++){
		int n;
		scanf("%d",&n);
		scanf("%lf",&a[n]);
	}
	cin>>K2;
	for(int i=0;i<K2;i++){
		int n;
		scanf("%d",&n);
		scanf("%lf",&b[n]);
		for(int j=0;j<1001;j++){
			if(a[j]!=0){
				c[j+n]+=b[n]*a[j];
			}
		}
	}
	int count=0;
	for(int i=0;i<2002;i++){
		if(c[i]!=0) count++;
	}
	if(count==0) cout<<0;
	else{
		cout<<count<<" ";
		bool flag=false;
		for(int i=2001;i>=0;i--){// 每输入一个b,就和前面所有a进行相乘，下标相加
			if(c[i]!=0){
				if(flag) cout<<" ";
				flag=true;
				printf("%d %.1lf",i,c[i]);
			}
		}
	}
	return 0;
}

