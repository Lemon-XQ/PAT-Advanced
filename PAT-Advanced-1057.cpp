#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Stack{
	int size;
	int data[100001];
	Stack(){
		size=0;
		fill(data,data+100001,-1);
	}
};

int main(){
	int N;
	cin>>N; getchar();
	Stack stack,tmp;
	int index=0,table[100001]={0},block[316]={0};// sqrt(100001)=316，分块思想，两次查询
	for(int i=0;i<N;i++){
		string str;
		getline(cin,str);
		if(str=="PeekMedian"){
			if(stack.size==0) cout<<"Invalid"<<endl;
			else{
				int med=stack.size/2.0+0.5,sum=0;
				int block_num=316;
				for(int i=0;i<block_num;i++){// 查询在哪个块
					sum+=block[i];
					if(sum>=med){
						sum-=block[i];
						// 查询在块内哪个元素
						for(int j=i*block_num;j<i*block_num+block_num;j++){
							sum+=table[j];
							if(sum>=med){
								cout<<j<<endl;
								break;
							}
						}
						break;
					}
				}
			}
		}else if(str=="Pop"){
			if(stack.size==0) cout<<"Invalid"<<endl;
			else{
				int num=stack.data[stack.size-1];
				cout<<num<<endl;
				table[num]--;
				block[num/316]--;
				stack.size--;
				stack.data[--index]=-1;
			}
		}else{
			int num=atoi(str.substr(5,str.length()-5).c_str());
			stack.data[index++]=num;
			stack.size++;
			table[num]++;
			block[num/316]++;
		}
	}
	return 0;
}

