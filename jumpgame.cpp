#include<bits/stdc++.h>
using namespace std;

const int d[] = {0,1};

int n;
int arr[110][110];
int vis[110][110];

int vpos(int x,int y){
	return x>0&&x<=n&&y>0&&y<=n;
}

void TC(){
	memset(arr,0,sizeof(arr));
	memset(vis,0,sizeof(vis));
	
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
		}
	}
	
	queue<int> q;
	q.push(1);q.push(1);
	vis[1][1]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		int y=q.front();q.pop();
		if(x==n&&y==n){
			cout<<"YES\n";
			return;
		}
		for(int i=0;i<2;i++){
			int nx=x+d[i]*arr[x][y],ny=y+d[i^1]*arr[x][y];
			if(vpos(nx,ny)&&!vis[nx][ny]){
				q.push(nx);q.push(ny);
				vis[nx][ny]=1;
			}
		}
	}
	cout<<"NO\n";
	
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
