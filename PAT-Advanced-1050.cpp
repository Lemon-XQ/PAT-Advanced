#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    string str1,str2;
    getline(cin,str1);
	getline(cin,str2);
	map<char,int> m;
	for(int i=0;i<str2.length();i++){
		m[str2[i]]=1;// ��ʾ���ַ����ֹ�
	}
	for(int i=0;i<str1.length();i++){
		if(m[str1[i]]==0) cout<<str1[i];// û��str2����ֹ��Ŀ������
	}
	return 0;
}
