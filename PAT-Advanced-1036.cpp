#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student{
	string name;
	string id;
	int score;
	student(string _name,string _id,int _score){
		id=_id;
		name=_name;
		score=_score;
	}
};

bool comp_1(student a,student b){
	return a.score<b.score;
}

bool comp_2(student a,student b){
	return a.score>b.score;
}

int main(){
	int N;
	cin>>N;
	vector<student> female,male;
	for(int i=0;i<N;i++){
		string str1,str2,str3;
		int score;
		cin>>str1>>str2>>str3>>score;
		if(str2=="M") male.push_back(student(str1,str3,score));
		else female.push_back(student(str1,str3,score));
	}
	bool absent=false;
	if(!female.empty()){
		sort(female.begin(),female.end(),comp_2);
		cout<<female[0].name<<" "<<female[0].id<<endl;
	}else{
		cout<<"Absent"<<endl;
		absent=true;
	}
	if(!male.empty()){
		sort(male.begin(),male.end(),comp_1);
		cout<<male[0].name<<" "<<male[0].id<<endl;
	}else{
		cout<<"Absent"<<endl;
		absent=true;
	}
	if(!absent) cout<<female[0].score-male[0].score<<endl;
	else cout<<"NA"<<endl;
	return 0;
}

