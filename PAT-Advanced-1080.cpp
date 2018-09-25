#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct record{
	int id;
	int ge,gi;
	int total;
	int choices[5];
};

bool comp(record a,record b){
	if(a.total!=b.total) return a.total>b.total;
	return a.ge>b.ge;
}

int main(){
    int N,M,K;
    cin>>N>>M>>K;
    int quota[M];
    for(int i=0;i<M;i++) scanf("%d",&quota[i]);
    vector<record> v;
    for(int i=0;i<N;i++){
    	record r;
    	r.id=i;
		scanf("%d %d",&r.ge,&r.gi);
		r.total=r.ge+r.gi;
		for(int j=0;j<K;j++) scanf("%d",&r.choices[j]);
		v.push_back(r);
	}
	sort(v.begin(),v.end(),comp);// 按成绩排名
	vector<int> school[M];// 存储每个学校的录取学生id
	int prev[M];// 每个学校最后一个录取的id
	for(int i=0;i<M;i++) prev[i]=-1;
	// 对每个学生的每个志愿，若符合要求则录取
	for(int i=0;i<v.size();i++){
		for(int j=0;j<K;j++){
			int choice=v[i].choices[j];
			int stu_prev=prev[choice];
			if(quota[choice]>0 || (stu_prev!=-1 && v[stu_prev].total==v[i].total && v[stu_prev].ge==v[i].ge)){
				school[choice].push_back(v[i].id);
				prev[choice]=i;
				quota[choice]--;
				break;
			}
		}
	}
	for(int i=0;i<M;i++){
		bool flag=false;
		sort(school[i].begin(),school[i].end(),less<int>());// 按id排序
		for(int j=0;j<school[i].size();j++){
			if(flag) printf(" ");
			printf("%d",school[i][j]);
			flag=true;
		}
		printf("\n");
	}

/* 原来理解错了题意：学校录取学生是先看分数，再看志愿顺序
	int finish[M],school[M][N];
	for(int i=0;i<M;i++){
		finish[i]=0;
		for(int j=0;j<N;j++) school[i][j]=-1;
	} 
	for(now=0;now<K;now++){
		sort(v.begin(),v.end(),comp);
		for(int i=0;i<M;i++){
			if(finish[i]==0){
				for(int j=0;j<v.size();j++){
					if(v[j].choices[now]>i) break;
					if(v[j].choices[now]==i){
						if(v[j].admit!=1 && (quota[i]>0 || (j!=0 && v[j].total==v[j-1].total && v[j].ge==v[j-1].ge))){
							if(quota[i]>0) quota[i]--;
							v[j].admit=1;
							school[i][v[j].id]=1;
							if(quota[i]==0){
								finish[i]=1;
								break;
							}
						}
					}
				}
			}
		}
	}*/
	return 0;
}

