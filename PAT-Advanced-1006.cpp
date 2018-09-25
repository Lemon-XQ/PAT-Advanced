#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct record{
	string id;
	string in,out;
	record(string _id,string _in,string _out){
		id=_id;
		in=_in;
		out=_out;
	}
};

bool comp_1(record a,record b){
	return a.in<b.in;
}

bool comp_2(record a,record b){
	return a.out>b.out;
}

int main(){
	int N;
	cin>>N;
	vector<record> v;
	for(int i=0;i<N;i++){
		string str1,str2,str3;
		cin>>str1>>str2>>str3;
		v.push_back(record(str1,str2,str3));
	}
	sort(v.begin(),v.end(),comp_1);// 找最早来的
	cout<<v[0].id<<" ";
	sort(v.begin(),v.end(),comp_2);// 找最后走的
	cout<<v[0].id<<endl;
	return 0;
}

