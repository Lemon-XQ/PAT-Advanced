#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	string suffix[9]={"","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi"};
	string s[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	string str;
	cin>>str;
	if(str[0]=='-'){
		cout<<"Fu ";
		str.erase(0,1);
	}
	if(str=="0"){// 注意特殊情况
		cout<<"ling"<<endl;
		return 0;
	}
	vector<string> ans;
	int index=0;
	for(int i=str.length()-1;i>=0;i--,index++){
		if(str[i]=='0'){
			if(i!=str.length()-1 && str[i+1]!='0'){
				ans.push_back("ling");
			}
		}else{
			if(index>=5 && index<=7 && str[i+1]=='0') ans.push_back("Wan");// 10万100万1000万的情况
			if(index!=0) ans.push_back(suffix[index]);// 注意不要push空串
			ans.push_back(s[str[i]-'0']);
		}
	}
	reverse(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		cout<<ans[i];
		if(i!=ans.size()-1) cout<<" ";
	}
	return 0;
}

