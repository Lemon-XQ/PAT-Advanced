#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin>>N;
	getchar();
	string s[N];
	int min_len=256;
	// ˼·�����ҵ�����ַ������ȣ�Ҳ������󹫹���׺�ĳ��ȣ���ÿ���ַ�����ת���ӵ�һλ��ʼ���һ���ַ����Ƚ�
	// �����һλ�Ͳ���ͬ�����nai���������indexΪ��һ������ͬ��������������һ���ַ����Ƚϣ������index��Χ��
	// ���ֲ���ͬ���ַ��������index
	for(int i=0;i<N;i++){
		string str;
		getline(cin,str);
		if(str.length()<min_len) min_len=str.length();
		reverse(str.begin(),str.end());
		s[i]=str;
	}
	int index=min_len;
	for(int i=1;i<N;i++){
		for(int j=0;j<index;j++){
			if(s[i][j]!=s[0][j]){
				if(j==0){
					cout<<"nai"<<endl;
					return 0;
				}else{
					index=j;
				}
			}
		}
	}
	string ans=s[0].substr(0,index);
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
	return 0;
}
