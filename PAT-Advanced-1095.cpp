#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

struct record{
	char id[8];
	int time;
	int in_time,out_time;
	int last_sec;
	char status[4];
};

bool comp(record a,record b){
	if(strcmp(a.id,b.id)!=0) return strcmp(a.id,b.id)<0;
	return a.time<b.time;
}

bool comp2(record a,record b){
	return a.in_time<b.in_time;
}

bool comp3(record a,record b){
	if(a.last_sec==b.last_sec) return strcmp(a.id,b.id)<0;
	return a.last_sec>b.last_sec;
}

//int calcSec(string in_time,string out_time){
//	int hour_in=atoi(in_time.substr(0,2).c_str());
//	int hour_out=atoi(out_time.substr(0,2).c_str());
//	int min_in=atoi(in_time.substr(3,2).c_str());
//	int min_out=atoi(out_time.substr(3,2).c_str());
//	int sec_in=atoi(in_time.substr(6,2).c_str());
//	int sec_out=atoi(out_time.substr(6,2).c_str());
//	return sec_out+min_out*60+hour_out*3600 -(sec_in+min_in*60+hour_in*3600);
//}

int calcTime(int hh,int mm,int ss){
	return ss+mm*60+hh*3600;
}
int main(){
    int N,K;
    cin>>N>>K;
    vector<record> v,v2;
    for(int i=0;i<N;i++){
    	record r;
		int hh,mm,ss;
		scanf("%s %d:%d:%d %s",r.id,&hh,&mm,&ss,r.status);
		r.time=calcTime(hh,mm,ss);
    	v.push_back(r);
	}
	sort(v.begin(),v.end(),comp);// 按车牌号排序，同个车牌号按time排序
	for(int i=0;i<v.size()-1;i++){
		// 找同个车牌号的相邻的in-out记录
		if(!strcmp(v[i].id,v[i+1].id) && !strcmp(v[i].status,"in") && !strcmp(v[i+1].status,"out")){
			record r;
			strcpy(r.id,v[i].id);
			r.in_time=v[i].time;
			r.out_time=v[i+1].time;
			r.last_sec=v[i+1].time-v[i].time;
			v2.push_back(r);
			i++;// 跳过这对记录
		}
	}
	sort(v2.begin(),v2.end(),comp2);// 按到达时间排序
	// 对每个查询，遍历记录（离开的那一刻不能算在场）
	for(int i=0;i<K;i++){
		int query,hh,mm,ss;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		query=calcTime(hh,mm,ss);
		int count=0;
		for(int j=0;j<v2.size();j++){
			if(v2[j].in_time > query) break;
			if(v2[j].out_time > query){
				count++;
			}
		}
		printf("%d\n",count);
	}
	sort(v2.begin(),v2.end(),comp);// 按车牌号排序
	v.clear();
	// 合并同个车牌号的记录
	for(int i=0;i<v2.size()-1;i++){
		if(!strcmp(v2[i].id,v2[i+1].id)){
			v2[i+1].last_sec+=v2[i].last_sec;
		}else{
			v.push_back(v2[i]);
		}
		// if(i==v2.size()-2) v.push_back(v2.back());// 最后一个
	}
	v.push_back(v2.back());// 最后一个（当v2只有1个元素时就是第一个）
	sort(v.begin(),v.end(),comp3);// 按停留时长和id排序
	int max=v[0].last_sec;
	for(int i=0;i<v.size();i++){
		if(max==v[i].last_sec){
			printf("%s ",v[i].id);
		}else{
			break;
		}
	}
	printf("%02d:%02d:%02d\n",max/3600,max%3600/60,max%60);
	return 0;
}

