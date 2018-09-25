#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int INF=0x3fffffff;

int toSecond(int hh,int mm,int ss){
	return hh*60*60+mm*60+ss;
}

int MAX=toSecond(21,0,0),MIN=toSecond(8,0,0);

struct Table{
	int endTime,serve;
	bool vip;
	Table(){
		vip=false;
		endTime=MIN;
		serve=0;
	}
};

struct people{
	int arriveTime,serveTime;
	int P;
	bool vip;
	people(int _a,int _P,bool _v){
		arriveTime=serveTime=_a;
		P=_P;
		vip=_v;
	}
};

bool comp(people a,people b){
	return a.arriveTime<b.arriveTime;
}

bool comp_2(people a,people b){
	return a.serveTime<b.serveTime;
}

void print(int s){
	int hh=s/3600;
	int mm=s%3600/60;
	int ss=s%60;
	printf("%02d:%02d:%02d ",hh,mm,ss);
}

int main(){
	int N,K,M;
	cin>>N;
	vector<people> v;
	for(int i=0;i<N;i++){
		int tag;
		int hh,mm,ss,P,time;
		scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&P,&tag);
		time=toSecond(hh,mm,ss);
		P=P>120?120:P;// 最多两小时
		if(time<MAX) v.push_back(people(time,P*60,tag));
	}
	sort(v.begin(),v.end(),comp);// 按到达时间排序
	cin>>K>>M;
	Table table[K+1];
	for(int i=0;i<M;i++){
		int num;
		cin>>num;
		table[num].vip=true;
	}
	bool flag[v.size()];
	fill(flag,flag+v.size(),false);
	for(int i=0;i<v.size();i++){
		if(flag[i]) continue;
		people& front=v[i];
//		print(front.arriveTime);
		int minEndTime=INF,id=-1;
		for(int j=1;j<=K;j++){
//			print(table[j].endTime);
			if(table[j].endTime<minEndTime){
				id=j;
				minEndTime=table[j].endTime;
			}
		}
//		cout<<endl;
		if(table[id].endTime>=MAX){
			front.serveTime=MAX;
			continue;// 21:00以后才能开局的无视
		}
		if(table[id].vip==front.vip){// 同为true/false
			if(table[id].endTime>front.arriveTime){// 来的时候没有空桌
				front.serveTime=table[id].endTime;
			}
			table[id].endTime=front.serveTime+front.P;
			table[id].serve++;
		}else if(table[id].vip==true && front.vip==false){
			int j;
			for(j=i+1;j<v.size();j++){
				if(v[j].vip==true) break;
			}
			// 有VIP在table空闲之前到达（队列中）
			if(j!=v.size() && v[j].arriveTime<=table[id].endTime){
//			if(j!=v.size()){
				i--;
				flag[j]=true;// 插队
				if(table[id].endTime>v[j].arriveTime){// 来的时候没有空桌
					v[j].serveTime=table[id].endTime;
				}
				table[id].endTime=v[j].serveTime+v[j].P;
			}else{
				if(table[id].endTime>front.arriveTime){// 来的时候没有空桌
					front.serveTime=table[id].endTime;
				}
				table[id].endTime=front.serveTime+front.P;
			}
			table[id].serve++;
        }else{// false true
			int j;
			for(j=1;j<=K;j++){
				if(table[j].vip==true && table[j].endTime==minEndTime) break;
			}
			cout<<j<<endl;
			if(j!=K+1){// 有空闲的vip桌
				if(table[j].endTime>front.arriveTime){// 来的时候没有空桌
					front.serveTime=table[j].endTime;
				}
				table[j].endTime=front.serveTime+front.P;
				table[j].serve++;
			}else{
				if(table[id].endTime>front.arriveTime){// 来的时候没有空桌
					front.serveTime=table[id].endTime;
				}
				table[id].endTime=front.serveTime+front.P;
				table[id].serve++;
			}
		}
	}
	sort(v.begin(),v.end(),comp_2);// 按开始服务时间排序
	for(int i=0;i<v.size();i++){
		if(v[i].serveTime>=MAX) continue;
		int hh=v[i].arriveTime/3600;
		int mm=v[i].arriveTime%3600/60;
		int ss=v[i].arriveTime%60;
		int hh2=v[i].serveTime/3600;
		int mm2=v[i].serveTime%3600/60;
		int ss2=v[i].serveTime%60;
		printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",hh,mm,ss,hh2,mm2,ss2,round((v[i].serveTime-v[i].arriveTime)/60.0));
	}
	for(int i=1;i<=K;i++){
		if(i!=1) cout<<" ";
		cout<<table[i].serve;
	}
	return 0;
}

