#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct record{
	int id;
	int score[6]={0};
	int total=0;
	int count;
	int status;
	int rank;
	record(){// 预先分配空间
	  for(int i=0;i<6;i++) score[i]=-2;
	  count=0;
	  status=0;
	  rank=0;
	  total=0;
	}
};

bool comp(record a,record b){
	if(a.total==b.total){
		if(a.count==b.count) return a.id<b.id;
		return a.count>b.count;
	}
	return a.total>b.total;
}

int main(){
    int N,K,M;
    cin>>N>>K>>M;
    int p[K];
    for(int i=0;i<K;i++) cin>>p[i];
    map<int,record> m;
    vector<record> v;
    for(int i=0;i<M;i++){
    	int id;
    	int problem,score;
    // 	cin>>id>>problem>>score;
    	scanf("%d %d %d",&id,&problem,&score);
    	if(m.count(id)==1){
    		if(score>m[id].score[problem]){
//    			m[id].total+=score-m[id].score[problem];
    			m[id].score[problem]=score;
			}
		}else{
			record r;
			r.id=id;
			r.score[problem]=score;
//			r.total=score;
			m[id]=r;
		}
	}
	for(map<int,record>::iterator it=m.begin();it!=m.end();it++){
		for(int i=1;i<=K;i++){
			if(it->second.score[i]!=-2 && it->second.score[i]!=-1){
				it->second.status=1;
				it->second.total+=it->second.score[i];
			}
			if(it->second.score[i]==p[i-1]) it->second.count++;
		}
		v.push_back(it->second);
	}
	sort(v.begin(),v.end(),comp);
	int prev=0;// 前一个记录索引
	v[0].rank=1;
	for(int i=0;i<v.size();i++){
		if(v[i].status!=1) break;
		if(v[i].total==v[prev].total) v[i].rank=v[prev].rank;
		else v[i].rank=i+1;
		printf("%d %05d %d ",v[i].rank,v[i].id,v[i].total);
		for(int j=1;j<=K;j++){
			if(v[i].score[j]==-2) printf("-");
			else if(v[i].score[j]==-1) printf("0");
			else printf("%d",v[i].score[j]);
			if(j!=K) printf(" ");
		}
		printf("\n");
		prev=i;
	}
	return 0;
}

