#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

bool check(string num){
	int arr[21]={0};
	sort(num.begin(),num.end());
 	for(int i=0;i<num.length();i++){
		arr[num[i]-'0']++;
	}
	for(int i=1;i<=num[num.length()-1]-'0';i++){
		if(arr[i]==0) return false;
	}
	return true;
}

int main(){
	string num,ans;
	cin>>num;
	int offset=0;
	bool flag=check(num);
	for(int i=num.length()-1;i>=0;i--){
		int tmp=(num[i]-'0')*2+offset;
		if(tmp>=10) offset=tmp/10;
		else offset=0;
		num[i]=tmp%10+'0';
	}
	bool flag2=check(num);
	if(offset!=0 || !flag || !flag2){
		if(offset!=0){
			num.insert(0,1,'0'+offset);
		}
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
	cout<<num<<endl;
	return 0;
}

