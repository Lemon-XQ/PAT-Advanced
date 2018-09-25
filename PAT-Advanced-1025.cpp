#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct record{
	string id;
	int rank_local,rank_final;
	int location;
	int score;
};

bool comp(record a,record b){
	if(a.score==b.score) return a.id<b.id;
	return a.score>b.score;
}

int main(){
    int N;
    cin>>N;
    vector<record> v_final;
    for(int i=0;i<N;i++){
    	int K;
    	cin>>K;
    	vector<record> v_local;
    	for(int j=0;j<K;j++){
    		record r;
    		cin>>r.id>>r.score;
    		r.location=i+1;
    		v_local.push_back(r);
		}
		sort(v_local.begin(),v_local.end(),comp);
		v_local[0].rank_local=1;
		v_final.push_back(v_local[0]);
		for(int j=1;j<v_local.size();j++){
			if(v_local[j].score != v_local[j-1].score) v_local[j].rank_local=j+1;
			else v_local[j].rank_local=v_local[j-1].rank_local;
			v_final.push_back(v_local[j]);
		}
	}
	sort(v_final.begin(),v_final.end(),comp);
	v_final[0].rank_final=1;
	cout<<v_final.size()<<endl;
	cout<<v_final[0].id<<" "<<1<<" "<<v_final[0].location<<" "<<v_final[0].rank_local<<endl;
	for(int j=1;j<v_final.size();j++){
		if(v_final[j].score != v_final[j-1].score) v_final[j].rank_final=j+1;
		else v_final[j].rank_final=v_final[j-1].rank_final;
		cout<<v_final[j].id<<" "<<v_final[j].rank_final<<" "<<v_final[j].location<<" "<<v_final[j].rank_local<<endl;
	}
	return 0;
}

