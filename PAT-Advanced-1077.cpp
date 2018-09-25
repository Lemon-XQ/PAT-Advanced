#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin>>N;
	getchar();
	string s[N];
	int min_len=256;
	// 思路：先找到最短字符串长度，也就是最大公共后缀的长度；将每个字符串反转，从第一位开始与第一个字符串比较
	// 如果第一位就不相同则输出nai，否则更新index为第一个不相同的索引；继续下一个字符串比较，如果在index范围内
	// 出现不相同的字符，则更新index
	for(int i=0;i<N;i++){
		string str;
		getline(cin,str);
		if(str.length()<min_len) min_len=str.length();
		reverse(str.begin(),str.end());
		s[i]=str;
	}
	int index=min_len;
	for(int i=1;i<N;i++){
		for(int j=0;j<index;j++){
			if(s[i][j]!=s[0][j]){
				if(j==0){
					cout<<"nai"<<endl;
					return 0;
				}else{
					index=j;
				}
			}
		}
	}
	string ans=s[0].substr(0,index);
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
	return 0;
}

