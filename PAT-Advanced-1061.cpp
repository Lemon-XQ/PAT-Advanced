#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

string DAYS[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main()
{
	string str_1,str_2,str_3,str_4;
	int flag = 0,day,hour,minute;
	cin >> str_1 >> str_2 >> str_3 >> str_4;
	for(int i=0;i<min(str_1.length(),str_2.length());i++){
		if(str_1[i]==str_2[i]){
			if(flag==0){
				if(str_1[i]>='A' && str_1[i]<='G'){
					day = str_1[i] - 'A';
					flag = 1;
				}
			}else{
				if(str_1[i]>='A' && str_1[i]<='N'){
					hour = str_1[i]-'A'+10;
					break;
				}
				else if(isdigit(str_1[i])){
					hour = str_1[i]-'0';
					break;
				}
			}
		}
	}
	for(int i=0;i<min(str_3.length(),str_4.length());i++){
		if(str_3[i]==str_4[i] && isalpha(str_3[i])){
			minute = i;
			break;
		}
	}
	cout<<DAYS[day]<<' ';
	printf("%02d:%02d",hour,minute);
	return 0;
}

