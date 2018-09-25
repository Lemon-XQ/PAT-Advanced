#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){ 
	int a,b;
    cin>>a>>b;  
    int sum=a+b;
    stringstream ss;
    ss<<sum;
    string str=ss.str();
    reverse(str.begin(),str.end());
    int index=3;
    while(str.length()>index && str[index]!='-'){// 负号后面不能加逗号 
    	str.insert(index,1,',');
    	index+=4;
    }
    reverse(str.begin(),str.end());
	cout<<str<<endl;
}