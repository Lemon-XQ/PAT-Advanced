#include <iostream>
#include <algorithm>

using namespace std;

struct student{
	int stunum;
	int de,cai;
	int kind;// 成绩分类，方便排序
};

int H;
bool comp(student a,student b){
	if(a.kind!=b.kind) return a.kind<b.kind;// 类别优先
	if(a.de+a.cai>b.de+b.cai) return true;
	else if(a.de+a.cai==b.de+b.cai){
		if(a.de>b.de) return true;// 德才总分相同按德排序
		else if(a.de==b.de) return a.stunum<b.stunum;// 德相同按学号排序
	}
	return false;
}

int main(){
	int N,L;
	scanf("%d %d %d",&N,&L,&H);
	//cin>>N>>L>>H;
	student* s=new student[N];
	int count=0,j=0;
	for(int i=0;i<N;i++){
		scanf("%d %d %d",&s[j].stunum,&s[j].de,&s[j].cai);
		//cin>>s[j].stunum>>s[j].de>>s[j].cai;
		if(s[j].de>=L && s[j].cai>=L){
			if(s[j].de>=H && s[j].cai>=H) s[j].kind=1;
			else if(s[j].de>=H && s[j].cai<H) s[j].kind=2;
			else if(s[j].de<H && s[j].cai<H && s[j].de>=s[j].cai) s[j].kind=3;
			else s[j].kind=4;
			count++;
			j++;// 只记录符合大于等于L标准的
		}
	}
	sort(s,s+count,comp);
	//cout<<count<<endl;
	printf("%d\n",count);
	for(int i=0;i<count;i++){
	  printf("%d %d %d\n",s[i].stunum,s[i].de,s[i].cai);
		//cout<<s[i].stunum<<" "<<s[i].de<<" "<<s[i].cai<<endl;
	}
}
