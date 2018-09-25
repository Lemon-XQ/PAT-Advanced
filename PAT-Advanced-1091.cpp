#include <iostream>
#include <queue>

using namespace std;

struct point{
	int x;
	int y;
	int z;
	point(int _x,int _y,int _z){
		x=_x; y=_y; z=_z;
	}
};

int M,N,L,T;
int ans=0;
int arr[62][1288][130];
bool visit[62][1288][130]={false};
void bfs(int a,int b,int c){
	queue<point> q;
	q.push(point(a,b,c));
	visit[a][b][c]=true;
	// 6个方向：向上，向下，向前，向后，向左，向右
	int dir[6][3]={{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
	int tmp=0;
	while(!q.empty()){
		point c=q.front();
		q.pop();
		tmp++;
		for(int i=0;i<6;i++){
			int x=c.x+dir[i][0],y=c.y+dir[i][1],z=c.z+dir[i][2];
			if(arr[x][y][z]==1 && visit[x][y][z]==false){
				q.push(point(x,y,z));
				visit[x][y][z]=true;
			}
		}
		
	}
	if(tmp>=T) ans+=tmp;
}

int main(){
    cin>>M>>N>>L>>T;
    for(int i=0;i<L+2;i++){
    	for(int j=0;j<M+2;j++){
    		for(int k=0;k<N+2;k++){
    			// 填充边界
    			if(i==0 || i==L+1 || j==0 || j==M+1 || k==0 || k==N+1) arr[i][j][k]=0;
    			else cin>>arr[i][j][k];
			}
		}
	}
	for(int i=1;i<L+1;i++){
		for(int j=1;j<M+1;j++){
			for(int k=1;k<N+1;k++){
				if(arr[i][j][k]==1 && visit[i][j][k]==false) bfs(i,j,k);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

