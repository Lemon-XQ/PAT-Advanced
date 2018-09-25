#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int INF=0x3fffffff;

int toSecond(int hh,int mm,int ss){
	return hh*60*60+mm*60+ss;
}

double toMin(int s){
	return s/60.0;
}

struct record{
	int P;
	int wait;
	int time;
	record(int _time,int _P,int _wait){
		time=_time; P=_P; wait=_wait;
	}
//	friend bool operator < (record a,record b){
//		return a.time>b.time;
//	}
};

bool comp(record a,record b){
	return a.time<b.time;
}

int main(){
	int N,K;
	cin>>N>>K;
	vector<record> q;// 模拟队列
//	priority_queue<record,vector<record> > q;
	int MAX=toSecond(17,0,0),MIN=toSecond(8,0,0);
	for(int i=0;i<N;i++){
		int hh,mm,ss,P,wait=0;
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&P);
		int time=toSecond(hh,mm,ss);
		if(time>MAX) continue;
		P=P>60?60:P;// 最多一小时
//		if(time<MIN){
//			wait=MIN-time;
//			time=MIN;
//		}
		q.push_back(record(time,P*60,wait));
	}
	sort(q.begin(),q.end(),comp);
	int endTime[K],wait_min=60*60,sum=0,leave_min=24*60*60;
	fill(endTime,endTime+K,MIN);
	for(int i=0;i<q.size();i++){
		int id=-1,minEndTime=INF;
		for(int j=0;j<K;j++){// 遍历所有窗口，更新最快结束时间及对应窗口号
			if(endTime[j]<minEndTime){
				minEndTime=endTime[j];
				id=j;
			}
		}
		if(endTime[id]<=q[i].time){// 有窗口空着，直接服务
			endTime[id]=q[i].time+q[i].P;
		}else{
			sum+=(endTime[id]-q[i].time);// wait
			endTime[id]+=q[i].P;
		}
	}
	if(q.size()==0) cout<<"0.0"<<endl;
	else printf("%.1lf\n",toMin(sum/(double)q.size()));
	return 0;
}

