#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct record{
	int id;
	string name;
	int score;
	record(){// ‘§œ»∑÷≈‰ø’º‰
	  name.resize(10);
	}
};

int C;
bool comp(record a,record b){
	if(C==1) return a.id<b.id;
	else if(C==2){
	  if(a.name==b.name) return a.id<b.id;
	  return a.name<b.name;
	}
	else if(C==3){
	  if(a.score==b.score) return a.id<b.id;
	  return a.score<b.score;
	}
}

int main(){
    int N;
    scanf("%d %d",&N,&C);
    // cin>>N>>C;
    vector<record> v;
    for(int i=0;i<N;i++){
    	record r;
    	char name[10];
    	scanf("%d %s %d",&r.id,&r.name[0],&r.score);
    	v.push_back(r);
	}
	sort(v.begin(),v.end(),comp);
	for(int i=0;i<v.size();i++){
	  printf("%06d %s %d\n",v[i].id,v[i].name.c_str(),v[i].score);
	}
	return 0;
}

