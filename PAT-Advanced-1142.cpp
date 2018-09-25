#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <sstream>

using namespace std;

const int MAXV=201;

int G[MAXV][MAXV];

int main(){
	int NV,NE,M;
	cin>>NV>>NE;
	for(int i=0;i<NE;i++){
		int a,b;
		cin>>a>>b;
		G[a][b]=1;
		G[b][a]=1;
	}
	cin>>M;
	for(int i=0;i<M;i++){
		int K;
		cin>>K;
		int arr[K];
		bool flag=true;
		map<int,int> m;
		for(int j=0;j<K;j++){
			cin>>arr[j];
			m[arr[j]]=1;
		}
		// 不是只有1个结点就一定是clique,需要判断其他结点与该点是否能邻接
		for(int j=0;j<K-1;j++){
			for(int t=j+1;t<K;t++){
				if(G[arr[j]][arr[t]]!=1){
					flag=false;
					break;
				}
			}
			if(!flag) break;
		}
		if(!flag) cout<<"Not a Clique"<<endl;
		else{
			int j;
			for(j=1;j<=NV;j++){
				if(m.count(j)==0){// 除了子集外的所有结点
					flag=true;
					for(int k=0;k<K;k++){
						if(G[j][arr[k]]!=1){
							flag=false;break;
						}
					}
					if(flag){
						cout<<"Not Maximal"<<endl;
						break;
					}
				}
			}
			if(j==NV+1) cout<<"Yes"<<endl;
		}
	}
	return 0;
}
