#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct node{
	node* lchild;
	node* rchild;
	int data;
};

// ����������߱�����������������
int N,arr[1001],CBT[1001],index=0;
void inTransverse(int root){
	if(root>N) return; // �ս��
	inTransverse(root*2);
	CBT[root]=arr[index++];
	inTransverse(root*2+1);
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++) cin>>arr[i];
	sort(arr,arr+N);// �������CBT��������������
	inTransverse(1);
	for(int i=1;i<=N;i++){
		if(i!=1) cout<<" ";
		cout<<CBT[i];
	}
	return 0;
}
