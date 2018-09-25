#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>

using namespace std;

const int MAXV=31;
const int INF=0x3fffffff;

int main(){
	string str1,str2;
	cin>>str1;
	str2=str1;
	reverse(str2.begin(),str2.end());
	if(str1==str2) cout<<str1<<" is a palindromic number."<<endl;
	else{
		int iter=0;
		while(iter<=10){
			string sum,tmp;
			int offset=0;
			for(int i=str1.length()-1;i>=0;i--){
				int ans=str1[i]-'0'+str2[i]-'0'+offset;
				sum.push_back((ans%10)+'0');
				offset=ans/10;
			}
			if(offset!=0) sum.push_back(offset+'0');
			tmp=sum;
			reverse(tmp.begin(),tmp.end());
			cout<<str1<<" + "<<str2<<" = "<<tmp<<endl;
			if(tmp==sum){
				cout<<tmp<<" is a palindromic number."<<endl;
				break;
			}else{
				iter++;
				if(iter==10){
					cout<<"Not found in 10 iterations."<<endl;
					break;
				}
				str1=tmp;
				str2.resize(str1.length());
				reverse_copy(str1.begin(),str1.end(),str2.begin());
			}
		}
	}
	return 0;
}
