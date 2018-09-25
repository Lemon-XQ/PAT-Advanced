#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
	int k;
	cin>>k;
	getchar();
	string str;
	getline(cin,str);
	map<char,int> m;
	vector<char> v;
	for(int i=0;i<str.length();i++){
		bool flag=false;
		for(int j=1;j<k && i+j<str.length();j++){
			if(str[i]==str[i+j]) flag=true;// ÓÐbug,ËäÈ»ÄÜac
			else{
				flag=false;
				break;
			} 
		}
		if(flag){
			if(m.count(str[i])==0) v.push_back(str[i]);
			m[str[i]]=1;
			i+=k-1;
		}else{
			m[str[i]]=0;
		}
	}
	for(int i=0;i<v.size();i++){
		if(m[v[i]]==1) cout<<v[i];
	}
	cout<<endl;
	for(int i=0;i<str.length();i++){
		bool flag=false;
		for(int j=0;j<v.size();j++){
			if(str[i]!=v[j] || str[i]==v[j] && m[v[j]]==0) flag=true;
			else{
				flag=false;break;
			} 
		}
		if(!flag) i+=k-1;
		cout<<str[i];
	}
	return 0;
}
