#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
	int Np,Ng;
	cin>>Np>>Ng;
	int w[Np],rank[Np];
	for(int i=0;i<Np;i++){
		cin>>w[i];
	}
	queue<int> q;
	for(int i=0;i<Np;i++){
		int order;
		cin>>order;
		q.push(order);
	}
	int temp=Np; //��ǰ�ֵ�������
	int group; //��ǰ�ֵ�����
	while (q.size()!=1) {
		if (temp%Ng!=0)  group=temp/Ng+1;
		else group=temp/Ng;
		//ö��ÿһ�顣ѡ�����Ľ�����һ��
		for (int i=0;i<group;i++) {
			int k=q.front();//���������������ı��
			for (int j=0;j<Ng;j++) {
				if (i*Ng+j>=temp)  break;
				int front=q.front();
				if (w[front]>w[k])
					k=front;
				rank[front]=group+1;
				q.pop();//����
			}
			q.push(k);//ʤ�����������
		}
		temp=group;
	}
	rank[q.front()]=1;//���һ��������ǵ�һ��
	for (int i=0;i<Np;i++) {
		if (i!=0) cout<" ";
		cout<<rank[i];
	}
	return 0;
}