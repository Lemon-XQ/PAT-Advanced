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
	int endTime,popTime;// ���ڵ�ǰ�����������ʱ�䡢���׿ͻ��ķ������ʱ��
	queue<int> q;
};

int main(){
	int N,M,K,Q;
	cin>>N>>M>>K>>Q;
	int MAX=toMin(17,0),MIN=toMin(8,0);
	int endTime[K],P[K];
	Window window[N];
	for(int i=0;i<K;i++){
		cin>>P[i];// ÿ���˵Ĵ���ʱ��
	}
	for(int i=0;i<N;i++){
		window[i].popTime=window[i].endTime=MIN;// ��ʼ��Ϊ8��
	}
	int index=0;
	for(int i=0;i<min(N*M,K);i++,index++){// �������д��ڵĺ�ѡ����
		// ѭ����ӣ���֤ÿ��ѡ�����������ŵ�
		window[index%N].q.push(index);
		window[index%N].endTime += P[index];
		// ÿ�����ڵ�һ���˵Ľ���ʱ��
		if(index<N) window[index].popTime=P[index];
		endTime[index]=window[index%N].endTime;// ��ӵĿͻ��Ľ���ʱ�����ȷ��
	}
	for(;index<K;index++){// ������Ŀͻ�
		int id=-1,minPoptime=INF;
		// �����д����е�һ��pop��
		for(int i=0;i<N;i++){
			if(window[i].popTime<minPoptime){
				minPoptime=window[i].popTime;
				id=i;
			}
		}
		window[id].q.pop();
		window[id].q.push(index);
		window[id].popTime+=P[window[id].q.front()];// popTime˳��
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
