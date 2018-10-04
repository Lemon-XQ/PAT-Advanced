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
	int temp=Np; //当前轮的总人数
	int group; //当前轮的组数
	while (q.size()!=1) {
		if (temp%Ng!=0)  group=temp/Ng+1;
		else group=temp/Ng;
		//枚举每一组。选出最大的进入下一轮
		for (int i=0;i<group;i++) {
			int k=q.front();//存放质量最大的老鼠的编号
			for (int j=0;j<Ng;j++) {
				if (i*Ng+j>=temp)  break;
				int front=q.front();
				if (w[front]>w[k])
					k=front;
				rank[front]=group+1;
				q.pop();//出队
			}
			q.push(k);//胜利的老鼠晋级
		}
		temp=group;
	}
	rank[q.front()]=1;//最后一个老鼠就是第一名
	for (int i=0;i<Np;i++) {
		if (i!=0) cout<" ";
		cout<<rank[i];
	}
	return 0;
}
