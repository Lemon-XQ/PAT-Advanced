#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct node{
	int id;
	int count;
	int M;
	double area;
	node(int _M,double _area){
		M=_M;
		area=_area;
		count=1;
	}
	node(){
		count=M=0; area=0;
	}
};

bool comp(node a,node b){
	if(a.area/(double)a.count==b.area/(double)b.count) return a.id<b.id;
	return a.area/(double)a.count>b.area/(double)b.count;
}

int father[10001];

int findFather(int x){
	int a=x;
	while(x!=father[x]) x=father[x];
//	while(a!=father[a]){// Â·¾¶Ñ¹Ëõ
//		int z=a;
//		a=father[a];
//		father[z]=x;
//	}
	return x;
}

void Union(int a,int b){
	int fa=findFather(a);
	int fb=findFather(b);
	if(fa!=fb) father[max(fa,fb)]=min(fa,fb);
}

int main(){
	int N;
	cin>>N;
	vector<node> v;
	v.resize(10001);
	bool visit[10001]={false};
	for(int i=0;i<10000;i++) father[i]=i;
	for(int i=0;i<N;i++){
		int id;
		int fa,mo,child,k,M;
		double area;
		scanf("%d %d %d %d",&id,&fa,&mo,&k);
		visit[id]=true;
		if(fa!=-1){
			visit[fa]=true;
			Union(id,fa);
		}
		if(mo!=-1){
			visit[mo]=true;
			Union(id,mo);
		}
		for(int j=0;j<k;j++){
		    scanf("%d",&child);
			visit[child]=true;
			Union(id,child);
		}
  		scanf("%d %lf",&M,&area);
		v[id]=node(M,area);
	}
	vector<node> ans;
	map<int,node> m;
	for(int i=0;i<10000;i++){
		if(visit[i]){
			int fa=findFather(i);
			m[fa].id=fa;
			m[fa].count++;
			m[fa].M+=v[i].M;
			m[fa].area+=v[i].area;
		}
	}
	for(map<int,node>::iterator it=m.begin();it!=m.end();it++){
		ans.push_back(it->second);
	}
	sort(ans.begin(),ans.end(),comp);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		printf("%04d %d %.3lf %.3lf\n",ans[i].id,ans[i].count,ans[i].M/(double)ans[i].count,ans[i].area/(double)ans[i].count);
	}
	return 0;
}
