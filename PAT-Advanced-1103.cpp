#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N,K,P;
vector<int> fac;// �洢������N��i��P����
vector<int> ans;// ������ŵĵ�������
vector<int> tmp;// ��ǰѡ�еĵ�����ɵ���ʱ����
int maxFacSum=-1;
// index��ʾѡ��fac�ڼ�����nowK��ʾ�Ѿ�ѡ�˼�����sum��ʾѡ����֮�ͣ�facSumΪѡ���ĵ���֮��
void dfs(int index,int nowK,int sum,int facSum){
	if(nowK==K && sum==N){
		if(facSum>maxFacSum){// ����֮�͸���
			maxFacSum=facSum;
			ans=tmp;
		}
		return;
	}
	if(sum>N || nowK>K) return;// �Ҳ�����
	if(index-1>=0){
		tmp.push_back(index);
		dfs(index,nowK+1,sum+fac[index],facSum+index);// ѡ
		tmp.pop_back();
		dfs(index-1,nowK,sum,facSum);// ��ѡ
	}
}

int main(){
    cin>>N>>K>>P;
    for(int i=0;pow(i,P)<=N;i++) fac.push_back(pow(i,P));
	dfs(fac.size()-1,0,0,0);
	if(maxFacSum==-1) cout<<"Impossible"<<endl;
	else{
		cout<<N<<" = "<<ans[0]<<"^"<<P;
		for(int i=1;i<ans.size();i++) cout<<" + "<<ans[i]<<"^"<<P;
	}
	return 0;
}
