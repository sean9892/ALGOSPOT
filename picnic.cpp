#include<bits/stdc++.h>
using namespace std;

int n,m;
int g[10][10];
int used[10];

int f(int s){
	if(s==n-1)return 1;
	if(used[s])return f(s+1);
	int sum=0;
	for(int i=s+1;i<n;i++){
		if(g[s][i]&&!used[i]){
			used[i]=1;
			sum+=f(s+1);
			used[i]=0;
		}
	}
	return sum;
}

void TC(){
	memset(g,0,sizeof(g));
	memset(used,0,sizeof(used));
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);
		g[a][b]=1;
	}
	cout<<f(0)<<"\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
