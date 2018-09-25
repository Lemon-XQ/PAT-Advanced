#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int N;
	int count=0;
	cin>>N;
    int factor = 1;
    int sum = 0,lower,high,cur;
    while(N/factor!=0){
        lower = N%(factor);
//        cout<<factor<<" "<<lower<<endl;
        high = N/(factor*10);
        cur = (N/factor)%10;// 当前位（从最后一位开始往前移）
        switch(cur){
	        case 0:
	            sum += high *factor;
	            break;
	        case 1:
	            sum += high *factor + lower+1;
	            break;
	        default:
	            sum += (high+1)*factor;
	        break;
        }
        factor=factor*10;
    }
    cout<<sum<<endl;
	return 0;
}
