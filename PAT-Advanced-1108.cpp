#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N,count=0;
	double sum=0;
	cin>>N;
	for(int i=0;i<N;i++){
		string str;
		cin>>str;
		int dot_index=-1,j;
		bool flag=true;
		for(j=0;j<str.length();j++){
			if(!isdigit(str[j])){
				if((str[j]!='.' && str[j]!='-' )|| ( str[j]=='-' && j!=0)){
					break;
				}
				if(str[j]=='.'){
					if(j==0) break;
					if(dot_index==-1){
						dot_index=j;
						if(str.length()-dot_index-1>2) break;
					}
					else{
						break;
					}
				}
			}
		}
		if(j==str.length()){
			double num=atof(str.c_str());
			if(num>=-1000 && num<=1000){
				sum+=num;
				count++;
				continue;
			}
		}
		cout<<"ERROR: "<<str<<" is not a legal number"<<endl;
	}
	if(count==0) cout<<"The average of 0 numbers is Undefined"<<endl;
	else if(count==1) printf("The average of 1 number is %.2lf\n",sum);
	else printf("The average of %d numbers is %.2lf\n",count,sum/(double)count);
	return 0;
}
