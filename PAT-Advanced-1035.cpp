#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
	int N;
	cin>>N;
	vector<pair<string,string> > v;
	for(int i=0;i<N;i++){
		string str1,str2;
		cin>>str1>>str2;
		if(str2.find('l')!=-1 || str2.find('1')!=-1 || str2.find('O')!=-1 || str2.find('0')!=-1){
			int len=str2.length();
			for(int j=0;j<len;j++){
				if(str2[j]=='l') str2[j]='L';
				else if(str2[j]=='1') str2[j]='@';
				else if(str2[j]=='0') str2[j]='%';
				else if(str2[j]=='O') str2[j]='o';
			}
			v.push_back(make_pair(str1,str2));
		}
	}
	int count=v.size();
	if(count==0){
		if(N==1) cout<<"There is 1 account and no account is modified"<<endl;
		else cout<<"There are "<<N<<" accounts and no account is modified"<<endl;
	}else{
		cout<<count<<endl;
		for(int i=0;i<v.size();i++) cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	return 0;
}

