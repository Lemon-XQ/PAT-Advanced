#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

struct record{
	int id;
	int count;
	record(){
		count=0;
	}
	record(int _id,int _count){
		count=_count;
		id=_id;
	}
	friend bool operator < (record a,record b){
		if(a.count==b.count) return a.id<b.id;
		return a.count>b.count;
	}
};

int main(){
	int N,K;
	cin>>N>>K;
	int arr[N];
	map<int,int> m;
	set<record> s;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		set<record>::iterator it;
		if(i!=0){
			cout<<arr[i]<<": ";
			int cnt=0;
			for(it=s.begin();it!=s.end();it++){
				cnt++;
				if(it!=s.begin()) cout<<" ";
				cout<<it->id;
				if(cnt==K) break;
			}
			cout<<endl;
		}
		if((it=s.find(record(arr[i],m[arr[i]])))!=s.end()) s.erase(it);
		m[arr[i]]++;
		s.insert(record(arr[i],m[arr[i]]));
	}

	return 0;
}
