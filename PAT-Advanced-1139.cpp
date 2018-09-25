#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> arr;
struct node {
    int a, b;
};
bool cmp(node x, node y) {
    return x.a != y.a ? x.a < y.a : x.b < y.b;
}
int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    vector<int> v[10000];
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        if (a.length() == b.length()) {
            v[abs(stoi(a))].push_back(abs(stoi(b)));
            v[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        arr[abs(stoi(a)) * 10000 + abs(stoi(b))] = arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int c, d;
        cin >> c >> d;
        vector<node> ans;
        for (int j = 0; j < v[abs(c)].size(); j++) {
            for (int k = 0; k < v[abs(d)].size(); k++) {
                if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k]) continue;
                if (arr[v[abs(c)][j] * 10000 + v[abs(d)][k]] == true)
                    ans.push_back(node{v[abs(c)][j], v[abs(d)][k]});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", int(ans.size()));
        for(int j = 0; j < ans.size(); j++)
            printf("%04d %04d\n", ans[j].a, ans[j].b);
    }
    return 0;
}
/*
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

const int MAXV=301;
const int INF=0x3fffffff;

map<string,vector<string> > Adj;
map<string,bool> visit;
vector<string> tmp;
vector<vector<string> > ans;
void dfs(string current,string des,int cnt){
	if(current==des){
	  	if(cnt!=3) return;
		if(tmp[0].length()==tmp[1].length() && tmp[2].length()==tmp[3].length()){
				ans.push_back(tmp);
		   }
		return;
	}
	for(int i=0;i<Adj[current].size();i++){
		string v=Adj[current][i];
		if(visit[v]==false){
			visit[v]=true;
			tmp.push_back(v);
			dfs(v,des,cnt+1);
			tmp.pop_back();
			visit[v]=false;
		}
	}
}

bool comp(pair<string,string> a,pair<string,string> b){
	if(a.first!=b.first) return abs(atoi(a.first.c_str()))<abs(atoi(b.first.c_str()));
	else return abs(atoi(a.second.c_str()))<abs(atoi(b.second.c_str()));;
}

int main(){
	int N,M,K;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		string a,b;// 不用int是因为不能区分0000和-0000
		cin>>a>>b;
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	cin>>K;
	for(int i=0;i<K;i++){
		string start,des;
		cin>>start>>des;
		vector<pair<string,string> > ans;
		// 最后一个点会超时，改成Adj一开始就记录同性集合，再用一个map保存所有关系对
		for(int j=0;j<Adj[start].size();j++){
			string v=Adj[start][j];
			if(v.length()==start.length() && v!=des){
				for(int k=0;k<Adj[v].size();k++){
					string v2=Adj[v][k];
					if(v2.length()==des.length() && v2!=des){
						for(int t=0;t<Adj[v2].size();t++){
							string v3=Adj[v2][t];
							if(v3==des){
								ans.push_back(make_pair(v,v2));
								break;
							}
						}
					}
				}
			}
		}
//		visit.clear();
//		ans.clear();
//		tmp.clear();
//		tmp.push_back(start);
//		visit[start]=true;
//		dfs(start,des,0);
		sort(ans.begin(),ans.end(),comp);
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++){
			printf("%04d %04d\n",abs(atoi(ans[i].first.c_str())),abs(atoi(ans[i].second.c_str())));
		}
	}
	return 0;
}
*/
