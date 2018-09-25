#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin>>N;
	int arr[N+1];
	for(int i=1;i<=N;i++) cin>>arr[i];
	bool flag=false;
	int a,b;
	// 列举每一种狼人组合
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			int lie_wolf=0,lie_human=0;
			for(int k=1;k<=N;k++){// 判断该狼人组合下是否满足1个撒谎的狼人+1个撒谎的村民
				if(k==i || k==j){// 狼人
					if(arr[k]>0 && arr[k]==i || arr[k]==j) lie_wolf++;
					else if(arr[k]<0 && abs(arr[k])!=i && abs(arr[k])!=j) lie_wolf++;
				}else{// 村民
					if(arr[k]>0 && arr[k]==i || arr[k]==j) lie_human++;
					else if(arr[k]<0 && abs(arr[k])!=i && abs(arr[k])!=j) lie_human++;
				}
			}
			if(lie_wolf==1 && lie_human==1){
				a=i;
				b=j;
				flag=true;
				break;
			}
		}
		if(flag) break;
	}
	if(flag) cout<<a<<" "<<b<<endl;
	else cout<<"No Solution"<<endl;
	return 0;
}
