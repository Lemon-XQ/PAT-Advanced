#include <iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int arr[N],left=0,count=0,index=1;
    for(int i=0;i<N;i++){
    	int num;
    	cin>>num;
		if(num!=i && num!=0) left++;
		arr[num]=i;
	}
	while(left>0){
		if(arr[0]!=0){
			swap(arr[0],arr[arr[0]]);
			left--;
		}else{
			while(index < N) {// ����С��ʼ���ҵ���һ�����ڱ�λ�����֣��´δӴ˴���ʼ������
                if(arr[index] != index) {
                    swap(arr[0], arr[index]);
                    break;
                }
                index++;
            }
		}
		count++;
	}
	cout<<count<<endl;
	return 0;
}
