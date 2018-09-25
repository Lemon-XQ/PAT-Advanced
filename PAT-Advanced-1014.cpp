#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int INF=0x3fffffff;

int toMin(int hh,int mm){
	return hh*60+mm;
}

struct Window{
	int endTime,popTime;// 窗口当前队伍的最后服务时间、队首客户的服务结束时间
	queue<int> q;
};

int main(){
	int N,M,K,Q;
	cin>>N>>M>>K>>Q;
	int MAX=toMin(17,0),MIN=toMin(8,0);
	int endTime[K],P[K];
	Window window[N];
	for(int i=0;i<K;i++){
		cin>>P[i];// 每个人的处理时间
	}
	for(int i=0;i<N;i++){
		window[i].popTime=window[i].endTime=MIN;// 初始化为8点
	}
	int index=0;
	for(int i=0;i<min(N*M,K);i++,index++){// 填满所有窗口的候选队列
		// 循环入队，保证每次选的是最少人排的
		window[index%N].q.push(index);
		window[index%N].endTime += P[index];
		// 每个窗口第一个人的结束时间
		if(index<N) window[index].popTime=P[index];
		endTime[index]=window[index%N].endTime;// 入队的客户的结束时间可以确定
	}
	for(;index<K;index++){// 黄线外的客户
		int id=-1,minPoptime=INF;
		// 找所有窗口中第一个pop的
		for(int i=0;i<N;i++){
			if(window[i].popTime<minPoptime){
				minPoptime=window[i].popTime;
				id=i;
			}
		}
		window[id].q.pop();
		window[id].q.push(index);
		window[id].popTime+=P[window[id].q.front()];// popTime顺移
		window[id].endTime+=P[index];
		endTime[index]=window[id].endTime;
	}
	for(int i=0;i<Q;i++){
		int query;
		cin>>query;
		query--;
		if(endTime[query]-P[query]>=MAX) printf("Sorry\n");
		else printf("%02d:%02d\n",endTime[query]/60,endTime[query]%60);
	}
	return 0;
}

