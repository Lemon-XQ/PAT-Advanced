#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    cin>>N;
	vector<int> v;
	int flag[10001]={0};
	for(int i=0;i<N;i++){
		int num;
		cin>>num;
		if(flag[num]==0){// ��һ�ζ�ȡnum
			v.push_back(num);
			flag[num]=1;
		}
		else flag[num]=-1;// ֤��num�����˶�Σ��������
	}
	bool exist=false;
	for(int i=0;i<v.size();i++){
		if(flag[v[i]]==1){
			exist=true;
			cout<<v[i]<<endl;
			break;
		}
	}
	if(!exist) cout<<"None"<<endl;
	return 0;
}
