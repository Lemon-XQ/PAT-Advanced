#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <sstream>

using namespace std;

int main(){
	int N;
	string D;
	cin>>D>>N;
	string str=D,tmp;
	for(int i=1;i<N;i++){
		tmp.clear();
		int cnt=1,j=0;
		for(j=0;j<str.length()-1;j++){
			if(str[j]==str[j+1]) cnt++;
			else{
				tmp.push_back(str[j]);
				stringstream ss;
				ss<<cnt;
				tmp+=ss.str();
				cnt=1;
			}
		}
		tmp.push_back(str[j]);
		stringstream ss;
		ss<<cnt;
		tmp+=ss.str();
		str=tmp;
	}
	cout<<str<<endl;
	return 0;
}
