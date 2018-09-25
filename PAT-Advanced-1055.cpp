#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct record{
	string name;
	int age;
	int net_worth;
	record(){// 预先分配空间
	  name.resize(10);
	}
};

bool comp(record a,record b){
	if(a.net_worth==b.net_worth){
		if(a.age==b.age) return a.name<b.name;
		return a.age<b.age;
	}
	return a.net_worth>b.net_worth;
}

int main(){
    int N,K;
    scanf("%d %d",&N,&K);
    vector<record> v;
    for(int i=0;i<N;i++){
    	record r;
		scanf("%s %d %d",&r.name[0],&r.age,&r.net_worth);
		v.push_back(r);
	}
	sort(v.begin(),v.end(),comp);// 如果每次查询都排序，再选出前M个会超时
	for(int i=0;i<K;i++){
		int M,Amin,Amax;
		scanf("%d %d %d",&M,&Amin,&Amax);
		printf("Case #%d:\n",i+1);
    	int count=0;
		for(int j=0;j<N;j++){
		  if(count==M) break;
			if(v[j].age<=Amax && v[j].age>=Amin){
			  count++;
			  printf("%s %d %d\n",v[j].name.c_str(),v[j].age,v[j].net_worth);
			}
		}
		if(count==0) printf("None\n");
	}
	return 0;
}

