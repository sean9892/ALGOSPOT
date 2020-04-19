#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int dp[110];

void TC(){
	int n;
	cin>>n;
	int r=dp[n]-dp[n/2];
	r=(r+mod)%mod;
	if(n%2==0)r-=dp[n/2-1];
	r=(r+mod)%mod;
	cout<<r<<"\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<101;i++){
		dp[i]=dp[i-1]+dp[i-2];
		dp[i]%=mod;
	}
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
