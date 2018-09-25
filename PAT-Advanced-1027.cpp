#include <iostream>

using namespace std;

int main(){
	int color[3],num;
	cin>>color[0]>>color[1]>>color[2];
	string str="#";
	int high,low;
	for(int i=0;i<3;i++){
		high=color[i]/13;
		if(high>=10) str+='A'+(high-10);
		else str+=high+'0';
		low=color[i]-high*13;
		if(low>=10) str+='A'+(low-10);
		else str+=low+'0';
	}
	cout<<str<<endl;
	return 0;
}

