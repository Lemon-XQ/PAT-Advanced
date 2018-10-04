#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;
    int a[N],b[N];
    for(int i=0;i<N;i++){
    	cin>>a[i];
    	b[i]=a[i];
    }
    sort(b,b+N);
    int count=0;
    vector<int> v;
    int max=0;
    for(int i=0;i<N;i++){
    	if(a[i]>max) max=a[i];
    	if(a[i]==b[i] && a[i]>=max){
	    	v.push_back(a[i]);
	    	count++;
	    }
    }
    cout<<count<<endl;
    for(int i=0;i<count-1;i++){
    	cout<<v[i]<<" ";
    }
    if(count>0) cout<<v[count-1];
    cout<<endl;
}
