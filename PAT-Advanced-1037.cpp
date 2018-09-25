#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int NC,NP;
    cin>>NC;
    int coupon[NC];
    for(int i=0;i<NC;i++) cin>>coupon[i];
    cin>>NP;
	int product[NP];
    for(int i=0;i<NP;i++) cin>>product[i];
    int max=0;
    sort(coupon,coupon+NC,greater<int>());
    sort(product,product+NP,greater<int>());
    int index1=-1,index2=-1;// 记录负数索引
    int sign_1=0,sign_2=0;
    for(int i=0;i<NC;i++){
    	if(coupon[i]>0 && product[i]>0) max+=coupon[i]*product[i];
    	if(!sign_1 && coupon[i]<0){
    		index1=i;
    		sign_1=1;
		}
		if(!sign_2 && product[i]<0){
    		index2=i;
    		sign_2=1;
		}
		if(sign_1 && sign_2) break;
	}
	if(sign_1&sign_2==1){// 两者都存在负数
		for(int i=NC-1,j=NP-1;i>=index1 && j>=index2;i--,j--){
			max+=coupon[i]*product[j];
		}
	}
	cout<<max<<endl;
	return 0;
}

