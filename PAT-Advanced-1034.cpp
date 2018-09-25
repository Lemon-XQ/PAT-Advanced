#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

struct node{
	int weight;
	string name;
	int sum;
	node(string _name,int _weight){
		name=_name; weight=_weight;sum=0;
	}
};

map<string,vector<node> > Adj;
map<string,bool> visit;
vector<pair<string,int> > ans;
int K;
void bfs(node n){
	int maxSum=0,total=0;
	set<string> s;
	string name;
	queue<node> q;
	q.push(n);
	while(!q.empty()){
		node c=q.front();
		visit[c.name]=true;
		q.pop();
		for(int i=0;i<Adj[c.name].size();i++){
			c.sum+=Adj[c.name][i].weight;
			if(visit[Adj[c.name][i].name]==false)
				q.push(Adj[c.name][i]);
		}
		if(s.count(c.name)==0) total+=c.sum;
		s.insert(c.name);
		if(c.sum>maxSum){
			maxSum=c.sum;
			name=c.name;
		}
	}
	if(s.size()>2 && total>2*K)// 一直过不去测试点2……没想到是2*k不是k
		ans.push_back(make_pair(name,s.size()));
}

bool comp(pair<string,int> a,pair<string,int> b){
	return a.first<b.first;
}

int main(){
	int N;
	cin>>N>>K;
	map<string,int> m;// 用map是因为可能有多条记录重复名字AAA BBB 10 AAA BBB 20
	for(int i=0;i<N;i++){
		string a,b;
		int len;
		cin>>a>>b>>len;
		m[a+b]+=len;
	}
	for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
		string a=it->first.substr(0,3);
		string b=it->first.substr(3,3);
		Adj[a].push_back(node(b,it->second));
		Adj[b].push_back(node(a,it->second));
	}
	for(map<string,vector<node> >::iterator it=Adj.begin();it!=Adj.end();it++){
		if(visit[it->first]==false){
			bfs(node(it->first,0));
		}
	}
	cout<<ans.size()<<endl;
	if(ans.size()!=0){
		sort(ans.begin(),ans.end(),comp);
		for(int i=0;i<ans.size();i++){
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	}
	return 0;
}

