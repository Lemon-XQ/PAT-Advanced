#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

const int MAXV=10001;
const int INF=0x3fffffff;

struct record{
	string id;
	int GP,GM,GF;
	int G;
	record(){
		GP=-1; GM=-1; GF=-1;
	}
	record(string _id,int _GP,int _GM,int _GF,int _G){
		id=_id; GP=_GP; GM=_GM; GF=_GF; G=_G;
	}
};

bool comp(record a,record b){
	if(a.G==b.G) return a.id<b.id;
	return a.G>b.G;
}

int main(){
	int P,M,N,score;
	cin>>P>>M>>N;
	map<string,record> m;
	string id;
	for(int i=0;i<P;i++){
		cin>>id>>score;
		m[id].GP=score;
	}
	for(int i=0;i<M;i++){
		cin>>id>>score;
		m[id].GM=score;
	}
	for(int i=0;i<N;i++){
		cin>>id>>score;
		m[id].GF=score;
	}
	vector<record> ans;
	for(map<string,record>::iterator it=m.begin();it!=m.end();it++){
		record r=it->second;
		string id=it->first;
		int GF=(r.GF==-1)?0:r.GF;
		int GM=(r.GM==-1)?0:r.GM;
		int G;// ²»ÓÃdouble
		if(GM>GF) G=GM*0.4+GF*0.6+0.5;
		else G=GF;
		if(G>=60 && r.GP>=200){
			ans.push_back(record(id,r.GP,r.GM,r.GF,G));
		}
	}
	sort(ans.begin(),ans.end(),comp);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].id<<" "<<ans[i].GP<<" "<<ans[i].GM<<" "<<ans[i].GF<<" "<<ans[i].G<<endl;
	}
	return 0;
}
