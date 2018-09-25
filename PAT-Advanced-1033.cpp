#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct station{
	double distance;
	double price;
};

bool comp(station a,station b){
	return a.distance<b.distance;
}

int main(){
    double Cmax,Davg;
	int D,N;
    cin>>Cmax>>D>>Davg>>N;
    vector<station> v,v2;
    v.resize(N+1);
    for(int i=0;i<N;i++){
    	cin>>v[i].price>>v[i].distance;
	}
	v[N].price=0; v[N].distance=D;// 终点
	sort(v.begin(),v.end(),comp);// 按距离排序
	if(v[0].distance!=0){
		cout<<"The maximum travel distance = 0.00"<<endl;
		return 0;
	}
	double max_distance=Cmax*Davg, cost=0, nowTank=0;// 满油行驶距离、总花费、当前油量
	int now=0;// 当前加油站编号
	while(now<N){
		int k=-1;// 记录距离最近最低油价的加油站编号
		double min_price=9999;
		for(int i=now+1;i<=N && v[i].distance-v[now].distance<=max_distance;i++){
			if(v[i].price<min_price){
				min_price=v[i].price;
				k=i;
				if(min_price<v[now].price){// 有一个比当前油价低的就退出循环
					break;
				}
			}
		}
		if(k==-1) break;// 无法到达下一个加油站
		double need=(v[k].distance-v[now].distance)/Davg;// 到k需要的油量
		if(min_price<v[now].price){// 低于当前油价，只加到刚好到k
			if(nowTank<need){// 不足need时补足
				cost+=(need-nowTank)*v[now].price;
				nowTank=0;// 到达k后油量为0
			}else{// 油量超过need
				nowTank-=need;
			}
		}else{// 加满
			cost+=(Cmax-nowTank)*v[now].price;
			nowTank=Cmax-need;// 到达k后油量减少need
		}
		now=k;
	}
	if(now==N){// 到达终点
		printf("%.2lf\n",cost);
	}else{
		printf("The maximum travel distance = %.2lf\n",v[now].distance+max_distance);
	}

	return 0;
}

