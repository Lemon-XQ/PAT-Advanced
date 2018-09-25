#include <iostream>

using namespace std;

int main(){
	int g1,s1,k1,g2,s2,k2,g,s,k;
	scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
	g=g1+g2;
	s=s1+s2;
	k=k1+k2;
	s+=k/29;
	k-=k/29*29;
	g+=s/17;
	s-=s/17*17;
	cout<<g<<"."<<s<<"."<<k<<endl;
	return 0;
}

