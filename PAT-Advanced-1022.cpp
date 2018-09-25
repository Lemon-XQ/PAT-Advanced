#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

struct book{
	string id;
	string title,author,publisher;
	string keyword;
	string year;
	book(string _id,string _title,string _author,string _publisher,string _year){
		id=_id; title=_title; author=_author; publisher=_publisher; year=_year;
	}
};
map<string,vector<string> > titleDb;
map<string,vector<string> > authorDb;
map<string,vector<string> > keywordDb;
map<string,vector<string> > publisherDb;
map<string,vector<string> > yearDb;

void search(string type,string query){
	if(type=="1"){// title
		if(titleDb.count(query)!=0){
			sort(titleDb[query].begin(),titleDb[query].end());
			for(int i=0;i<titleDb[query].size();i++) cout<<titleDb[query][i]<<endl;
			return;
		}
	}else if(type=="2"){// author
		if(authorDb.count(query)!=0){
			sort(authorDb[query].begin(),authorDb[query].end());
			for(int i=0;i<authorDb[query].size();i++) cout<<authorDb[query][i]<<endl;
			return;
		}
	}else if(type=="3"){// keyword
		if(keywordDb.count(query)!=0){
			sort(keywordDb[query].begin(),keywordDb[query].end());
			for(int i=0;i<keywordDb[query].size();i++) cout<<keywordDb[query][i]<<endl;
			return;
		}
	}else if(type=="4"){// publisher
		if(publisherDb.count(query)!=0){
			sort(publisherDb[query].begin(),publisherDb[query].end());
			for(int i=0;i<publisherDb[query].size();i++) cout<<publisherDb[query][i]<<endl;
			return;
		}
	}else if(type=="5"){// year
		if(yearDb.count(query)!=0){
			sort(yearDb[query].begin(),yearDb[query].end());
			for(int i=0;i<yearDb[query].size();i++) cout<<yearDb[query][i]<<endl;
			return;
		}
	}
	cout<<"Not Found"<<endl;
}

int main(){
	int N,M;
	cin>>N; getchar();
	for(int i=0;i<N;i++){
		string id,title,author,publisher,keywords;
		string year;
		getline(cin,id);
		getline(cin,title);
		getline(cin,author);
		getline(cin,keywords);
		getline(cin,publisher);
		getline(cin,year);
		int index=0,start=0;
		// 提取关键词
		while((index=keywords.find(' ',index+1))!=string::npos){
			string k=keywords.substr(start,index-start);
			keywordDb[k].push_back(id);
			start=index+1;
		}
		// 最后一个关键词
		string k=keywords.substr(start,keywords.length()-start);
		keywordDb[k].push_back(id);
		titleDb[title].push_back(id);
		authorDb[author].push_back(id);
		publisherDb[publisher].push_back(id);
		yearDb[year].push_back(id);
	}
	cin>>M; getchar();
	for(int i=0;i<M;i++){
		string str;
		getline(cin,str);
		cout<<str<<endl;
		int index=str.find(':');
		string num=str.substr(0,index);
		string info=str.substr(index+2,str.length()-index-2);
		search(num,info);
	}
	return 0;
}

