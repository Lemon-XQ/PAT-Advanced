#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <sstream>

using namespace std;

struct school{
	string id;
	int B,A,T;
	int total;
	int count;
	int rank;
	school(){
		B=A=T=count=0;
	}
	school(string _id,int _B,int _A, int _T,int _count){
		id=_id; B=_B; A=_A; T=_T;
		total=B/1.5+A+T*1.5;
		count=_count;
	}
};

string toLower(string str){
	for(int i=0;i<str.length();i++) str[i]=tolower(str[i]);
	return str;
}

bool comp(school a,school b){
	if(a.total==b.total){
		if(a.count==b.count) return a.id<b.id;
		return a.count<b.count;
	}
	return a.total>b.total;
}

int main(){
	int N;
	cin>>N;
	map<string,school> m;
	for(int i=0;i<N;i++){
		string id,school;
		int score;
		cin>>id>>score>>school;
		m[toLower(school)].count++;
		if(id[0]=='B') m[toLower(school)].B+=score;
		else if(id[0]=='A') m[toLower(school)].A+=score;
		else if(id[0]=='T') m[toLower(school)].T+=score;
	}
	cout<<m.size()<<endl;
	vector<school> ans;
	for(map<string,school>::iterator it=m.begin();it!=m.end();it++){
		school s=it->second;
		ans.push_back(school(it->first,s.B,s.A,s.T,s.count));
	}
	sort(ans.begin(),ans.end(),comp);
	ans[0].rank=1;
	for(int i=0;i<ans.size();i++){
		if(i!=0 && ans[i].total==ans[i-1].total) ans[i].rank=ans[i-1].rank;
		else ans[i].rank=i+1;
		cout<<ans[i].rank<<" "<<ans[i].id<<" "<<ans[i].total<<" "<<ans[i].count<<endl;
	}
	return 0;
}
