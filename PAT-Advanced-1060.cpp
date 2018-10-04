#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct num{
	string s;  //�洢0.xxxxxx��xxxxxx����
	int bit;  //�洢ָ��
};

int N;
string a,b;

num solve(string a){
	num tmp;
	int firstPos=-1, pointPos=-1;// firstpos��¼��һ����Ч����λ��pointpos��¼С����λ
	for(int i=0; i<a.size();i++){
		if(a[i]=='.')
			pointPos=i;
		else if(isdigit(a[i]) && a[i] != '0' && firstPos == -1){
			firstPos = i;
			tmp.s.push_back(a[i]);
		}
		else if(firstPos!=-1 && isdigit(a[i]))
			tmp.s.push_back(a[i]);
	}
	// ���û��С���㣬��ôĬ���������������С����
	if(pointPos == -1) pointPos = a.size();
	// firstPos��-1,��ô����һ����0
	if(firstPos == -1)
		firstPos = pointPos = a.size();
	// ���в�0
	if(tmp.s.size() < N) tmp.s.append(N-tmp.s.size(), '0');
	else tmp.s = tmp.s.erase(N);
	if(pointPos < firstPos) tmp.bit = pointPos - firstPos + 1;
	else tmp.bit = pointPos - firstPos;
	return tmp;
}
int main(){
	cin>>N>>a>>b;
	num result1,result2;
	result1 = solve(a);
	result2 = solve(b);
	if(result1.s == result2.s && result1.bit == result2.bit)
		printf("YES 0.%s*10^%d\n",result1.s.c_str(),result1.bit);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d\n",result1.s.c_str(),result1.bit,result2.s.c_str(),result2.bit);
	return 0;
}