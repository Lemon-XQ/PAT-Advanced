#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct num{
	string s;  //存储0.xxxxxx的xxxxxx部分
	int bit;  //存储指数
};

int N;
string a,b;

num solve(string a){
	num tmp;
	int firstPos=-1, pointPos=-1;// firstpos记录第一个有效数字位，pointpos记录小数点位
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
	// 如果没有小数点，那么默认在整数最后面有小数点
	if(pointPos == -1) pointPos = a.size();
	// firstPos是-1,那么数字一定是0
	if(firstPos == -1)
		firstPos = pointPos = a.size();
	// 进行补0
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
