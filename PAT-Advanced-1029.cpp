#include <iostream>
#include <algorithm>

using namespace std;
const int INF=0x7fffffff;
#define size 200001
int arr[size];

int main(){
	int N1,N2,i=0,j=0;
	scanf("%d",&N1);
	for(int i=0;i<N1;i++){
		scanf("%d",&arr[i]);
	}
	arr[N1]=INF;
	scanf("%d",&N2);
	int mid=(N1+N2-1)/2,count=0,num;
	scanf("%d",&num);
	for(count=0;count<mid;count++){// ����arr��������������λ��Ϊֹ
		if(num>arr[i]) i++;// �ҵ�����ĵط�
		else{
			j++;
			if(j<N2) scanf("%d",&num);
			else if(j==N2) num=INF;
			else break;
		}
	}
	cout<<min(arr[i],num)<<endl;
//	for(int j=i;j<N+i;j++){
//		scanf("%d",&arr[j]);
//	}
//	sort(arr,arr+N+i);// ���һ�����Ե�MLE
//	cout<<arr[(N+i-1)/2]<<endl;
	return 0;
}
