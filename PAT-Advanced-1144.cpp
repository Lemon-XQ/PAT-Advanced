#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> ans;
	for(int i=0;i<N;i++){
		int num;
		cin>>num;
		if(num>0) ans.push_back(num);
	}
	sort(ans.begin(),ans.end());
	if(ans.size()==0) cout<<1<<endl;
	else{
	    int start=0;
	  	for(int i=0;i<ans.size();i++){
	  		if(ans[i]!=start && ans[i]!=start+1){
	  			break;
	  		}else{
	  			start=ans[i];
	  		}
	  	}
	  	cout<<start+1<<endl;
	}

}
