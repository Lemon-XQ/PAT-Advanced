#include <iostream>
#include <algorithm>

using namespace std;

// �ַ���ƴ��������Сֵ
bool comp(string a,string b){
	return a+b<b+a;
}

int main(){
    int N;
    cin>>N;
	string arr[N];
	for(int i=0;i<N;i++) cin>>arr[i];
	sort(arr,arr+N,comp);
	string ans="";// ƴ�Ӻ���ַ���
	for(int i=0;i<N;i++){
		ans+=arr[i];
	}
	int i=0;
//	for(i=0;i<ans.length();i++){
//		if(ans[i]!='0') break;
//	}
//	ans=ans.substr(i,ans.length()-i);
	// ȥ��ǰ��0
	while(ans.size()>0 && ans[0]=='0'){
		ans.erase(0,1);
	}
	if(ans.empty()) cout<<0<<endl;
	else cout<<ans<<endl;
	return 0;
}
