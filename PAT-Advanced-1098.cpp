#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int before[101],after[101];
void downAdjust(int low,int high){
	int i=low,j=i*2;
	while(j<=high){
		if(j+1<=high && after[j+1]>after[j]){
			j++;
		}
		if(after[j]>after[i]){
			swap(after[j],after[i]);
			i=j;
			j=j*2;
		}else{
			break;
		}
	}
}

int main(){
	int N;
	cin>>N;
	for(int i=1;i<=N;i++) cin>>before[i];
	for(int i=1;i<=N;i++) cin>>after[i];
	int i,j;
	for(i=1;i<=N-1 && after[i]<=after[i+1];i++);// 第一个未排序的元素的前一个元素
	for(j=i+1;j<=N && before[j]==after[j];j++);// 从该元素后二者相同
	if(j==N+1){
		cout<<"Insertion Sort"<<endl;
		sort(after,after+i+2);
	}else{
		cout<<"Heap Sort"<<endl;
		for(i=N;i>1 && after[i]>=after[1];i--);// 找到堆底最后一个未排序的数
		swap(after[i],after[1]);
		downAdjust(1,i-1);// 调整堆顶
	}
	for(int i=1;i<=N;i++){
		if(i!=1) cout<<" ";
		cout<<after[i];
	}
	return 0;
}

