#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct record{
	string name;
	string id;
	int score;
};

bool comp(record a,record b){
	return a.score>b.score;
}

int main(){
    int N;
    cin>>N;
    vector<record> v;
    v.resize(N);
    for(int i=0;i<N;i++){
    	cin>>v[i].name>>v[i].id>>v[i].score;
	}
	int low,high;
	cin>>low>>high;
	sort(v.begin(),v.end(),comp);
	bool flag=false;
	for(int i=0;i<v.size();i++){
		if(v[i].score<low) break;
		if(v[i].score>=low && v[i].score<=high){
			flag=true;
			cout<<v[i].name<<" "<<v[i].id<<endl;
		}
	}
	if(!flag) cout<<"NONE"<<endl;
	return 0;
}

