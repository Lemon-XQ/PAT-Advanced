#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool comp(pair<string,int> a,pair<string,int> b){
	if(a.second!=b.second) return a.second>b.second;
	return a.first<b.first;
}

int main(){
	string str;
	getline(cin,str);
	transform(str.begin(),str.end(),str.begin(),::tolower);
	map<string,int> m;
	vector<pair<string,int> > v;
	int start=0;
	for(int i=0;i<str.length();i++){
		if(!isalnum(str[i]) && isalnum(str[start])){
			string word=str.substr(start,i-start);
			m[word]++;
			start=i+1;
		}else if(!isalnum(str[start])) start++;
	}
	// 处理最后一个单词（以换行符为结尾）
	if(isalnum(str[start])){
		string word=str.substr(start,str.length()-start);
		m[word]++;
	}
	for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
		// cout<<it->first<<" "<<it->second<<endl;
		v.push_back(make_pair(it->first,it->second));
	}
	sort(v.begin(),v.end(),comp);
	cout<<v[0].first<<" "<<v[0].second<<endl;
	return 0;
}
