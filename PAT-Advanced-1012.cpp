#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct student{
	string id;
//	int C,M,E,A;
	int grade[4];
	int rank[4];
//	char subject;
	student(string _id,int _C,int _M,int _E){
		id=_id;
		grade[1]=_C;
		grade[2]=_M;
		grade[3]=_E;
		grade[0]=(_C+_M+_E)/3;
	}
	student(){}
};

int now=0;
bool comp(student a,student b){
	return a.grade[now]>b.grade[now];
}

//bool comp_1(student a,student b){
//	return a.E>b.E;
//}
//bool comp_2(student a,student b){
//	return a.M>b.M;
//}
//bool comp_3(student a,student b){
//	return a.C>b.C;
//}
//bool comp_4(student a,student b){
//	return a.A>b.A;
//}

int main(){
	char subject[4]={'A','C','M','E'};
	int N,M;
	cin>>N>>M;
	map<string, int> m;// 记录id是否出现过
	vector<student> v,v2,v3,v4;
	for(int i=0;i<N;i++){
		string str;
		int _c,_m,_e;
		cin>>str>>_c>>_m>>_e;
		m[str]=1;
		v.push_back(student(str,_c,_m,_e));
	}
	map<string,student> ans;
	for(now=0;now<4;now++){
		sort(v.begin(),v.end(),comp);
		v[0].rank[now]=1;
		ans[v[0].id]=v[0];
		for(int i=1;i<N;i++){
			if(v[i].grade[now]==v[i-1].grade[now]){// 注意同个分数的排名相同 以及1 2 3 3 5不是1 2 3 3 4
				v[i].rank[now]=v[i-1].rank[now];
			}else{
				v[i].rank[now]=i+1;
			}
			ans[v[i].id]=v[i];
		}
	}
	
//	v2=v3=v4=v;
//	sort(v.begin(),v.end(),comp_1);// E
//	sort(v2.begin(),v2.end(),comp_2);// M
//	sort(v3.begin(),v3.end(),comp_3);// C
//	sort(v4.begin(),v4.end(),comp_4);// A
//	map<string,student> ans;
//	for(int i=0;i<v.size();i++){
//		v[i].rank=i+1;
//		v[i].subject='E';
//		if(i!=0 && v[i].E==v[i-1].E) v[i].rank=i;
//		for(int j=0;j<=i;j++){
//			if(v[i].id==v2[j].id || v[i].id==v3[j].id || v[i].id==v4[j].id){
//				v[i].rank=j+1;
//				if(v[i].id==v2[j].id){
//					if(j!=0 && v2[j].M==v2[j-1].M) v[i].rank=j;
//					v[i].subject='M';
//				} 
//				if(v[i].id==v3[j].id){
//					if(j!=0 && v3[j].C==v3[j-1].C) v[i].rank=j;
//					v[i].subject='C';
//				} 
//				if(v[i].id==v4[j].id){
//					if(j!=0 && v4[j].A==v4[j-1].A) v[i].rank=j;
//					v[i].subject='A';
//				}
//				break;
//			} 
//		}
//		ans[v[i].id]=v[i];
//	}
	for(int i=0;i<M;i++){
		string id;
		cin>>id;
		if(m[id]==0) cout<<"N/A"<<endl;
		else{
			int k=0;
			for(int j=0;j<4;j++){
				if(ans[id].rank[j]<ans[id].rank[k]) k=j;
			}
			cout<<ans[id].rank[k]<<" "<<subject[k]<<endl;
		}
	}
	return 0;
}

