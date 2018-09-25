#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct record{
	string name;
	string time;
	string state;
//	int day,hour,minute;
};

bool comp(record a,record b){
	return a.time<b.time;
}

int cost_table[24],cost_day=0;
int last_min=0;
double calcAmount(string online,string offline){
	int day_on=atoi(online.substr(0,2).c_str());
	int day_off=atoi(offline.substr(0,2).c_str());
	int hour_on=atoi(online.substr(3,2).c_str());
	int hour_off=atoi(offline.substr(3,2).c_str());
	int min_on=atoi(online.substr(6,2).c_str());
	int min_off=atoi(offline.substr(6,2).c_str());
	last_min=(day_off*24*60+hour_off*60+min_off)-(day_on*24*60+hour_on*60+min_on);
	double amount=0;
	// 求话费：步步逼近的方法，让时间渐渐逼近offline
	int tmp_min=min_on,tmp_hour=hour_on,tmp_day=day_on;
	while(tmp_min!=min_off || tmp_hour!=hour_off || tmp_day!=day_off ){
		amount+=cost_table[tmp_hour];
		tmp_min++;
		if(tmp_min==60){
			tmp_min=0;
			tmp_hour++;
		}
		if(tmp_hour==24){
			tmp_hour=0;
			tmp_min=0;
			tmp_day++;
		}
	}
// if(last_min>24*60) for(int i=0;i<day_off-day_on;i++) amount+=cost_day;
//	else if(day_on!=day_off) amount+=
//	if(hour_on==hour_off) amount+=cost_table[hour_on]*(min_off-min_on);
//	else{
//		amount+=cost_table[hour_on]*(60-min_on);
//		for(int j=hour_on+1;j<hour_off;j++) amount+=cost_table[j]*60;
//		amount+=cost_table[hour_off]*min_off;
//	}
	return amount;
}

int main(){
    for(int i=0;i<24;i++){
    	cin>>cost_table[i];
//    	cost_day+=cost_table[i]*60;
	} 
    int N;
    cin>>N;
//    vector<record> v;
    map<string,vector<record> > m;
    string month;
    for(int i=0;i<N;i++){
    	record r;
    	cin>>r.name>>r.time>>r.state;
    	month=r.time.substr(0,2);
    	r.time=r.time.substr(3,8);
    	m[r.name].push_back(r);
	}
	for(map<string,vector<record> >::iterator it=m.begin();it!=m.end();it++){
		sort(it->second.begin(),it->second.end(),comp);
		bool flag=false;// 判断用户是否存在有效通话记录
		for(int i=0;i<it->second.size()-1;i++){
			if(it->second[i].state=="on-line" && it->second[i+1].state=="off-line"){
				flag=true;
				break;
			}
		}
		if(flag){
			cout<<it->first<<" "<<month<<endl;
			double total=0;
			for(int i=0;i<it->second.size()-1;i++){
				if(it->second[i].state=="on-line" && it->second[i+1].state=="off-line"){
					string online=it->second[i].time,offline=it->second[i+1].time;
					double amount=calcAmount(online,offline);
					total+=amount;
					cout<<online<<" "<<offline<<" "<<last_min<<" ";
					printf("$%.2lf\n",amount*0.01);
					i++;
				}
			}
			printf("Total amount: $%.2lf\n",total*0.01);
		}
	}
	return 0;
}

