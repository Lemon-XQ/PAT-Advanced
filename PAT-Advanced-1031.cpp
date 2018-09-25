#include <iostream>

using namespace std;

int main(){
	string str;
	cin>>str;
	int n1=1,n2=3;
	int N=str.length();
//	n1=(N-3)/2;
	n1=(N+2)/3;// 注意上界的确定：n1+n2+n3=N+2
	n2=N-n1*2+2;
	for(int i=0;i<n1-1;i++){
		cout<<str[i];
		for(int j=0;j<n2-2;j++) cout<<" ";
		cout<<str[N-1-i]<<endl;
	}
	for(int i=0;i<n2;i++){
		cout<<str[n1-1+i];
	}
	return 0;
}

