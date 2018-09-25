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
	v[N].price=0; v[N].distance=D;// �յ�
	sort(v.begin(),v.end(),comp);// ����������
	if(v[0].distance!=0){
		cout<<"The maximum travel distance = 0.00"<<endl;
		return 0;
	}
	double max_distance=Cmax*Davg, cost=0, nowTank=0;// ������ʻ���롢�ܻ��ѡ���ǰ����
	int now=0;// ��ǰ����վ���
	while(now<N){
		int k=-1;// ��¼�����������ͼ۵ļ���վ���
		double min_price=9999;
		for(int i=now+1;i<=N && v[i].distance-v[now].distance<=max_distance;i++){
			if(v[i].price<min_price){
				min_price=v[i].price;
				k=i;
				if(min_price<v[now].price){// ��һ���ȵ�ǰ�ͼ۵͵ľ��˳�ѭ��
					break;
				}
			}
		}
		if(k==-1) break;// �޷�������һ������վ
		double need=(v[k].distance-v[now].distance)/Davg;// ��k��Ҫ������
		if(min_price<v[now].price){// ���ڵ�ǰ�ͼۣ�ֻ�ӵ��պõ�k
			if(nowTank<need){// ����needʱ����
				cost+=(need-nowTank)*v[now].price;
				nowTank=0;// ����k������Ϊ0
			}else{// ��������need
				nowTank-=need;
			}
		}else{// ����
			cost+=(Cmax-nowTank)*v[now].price;
			nowTank=Cmax-need;// ����k����������need
		}
		now=k;
	}
	if(now==N){// �����յ�
		printf("%.2lf\n",cost);
	}else{
		printf("The maximum travel distance = %.2lf\n",v[now].distance+max_distance);
	}

	return 0;
}
