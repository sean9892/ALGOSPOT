#include<bits/stdc++.h>
using namespace std;

const int dx[] = {-1,-1,-1,0,0,1,1,1};
const int dy[] = {-1,0,1,-1,1,-1,0,1};

int dp[5][5][10];

int n;
int r[10];
string a[5];
string s[10];

int vpos(int x,int y){
	return x>=0&&x<5&&y>=0&&y<5;
}

void setDP(const string &str){
	memset(dp,0,sizeof(dp));
	memset(r,0,sizeof(r));
	const int ss=str.size();
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			dp[i][j][ss-1]=(str[ss-1]==a[i][j]);
			if(str[ss-1]==a[i][j])r[ss-1]=1;
		}
	}
	for(int k=ss-2;k>=0;k--){
		if(!r[k+1])break;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(str[k]==a[i][j]){
					for(int w=0;w<8;w++){
						int nx=i+dx[w],ny=j+dy[w];
						if(vpos(nx,ny)&&dp[nx][ny][k+1]){
							dp[i][j][k]=1;
							r[k]=1;
							break;
						}
					}
				}
			}
		}
	}
}

void TC(){
	for(int i=0;i<5;i++)
		cin>>a[i];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		setDP(s[i]);
		cout<<s[i]<<" ";
		if(r[0])cout<<"YES\n";
		else cout<<"NO\n";
	}
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
