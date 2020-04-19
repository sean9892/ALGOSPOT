#include<bits/stdc++.h>
using namespace std;

int dp[110][110];
string s,t;

int match(int a,int b){
	if(dp[a][b]!=-1)return dp[a][b];
	while(a<s.size()&&b<t.size()&&(s[a]=='?'||s[a]==t[b])){
		a++;b++;
	}
	if(a==s.size())return dp[a][b]=(b==t.size());
	if(s[a]=='*'){
		for(int p=b;p<=t.size();p++){
			if(match(a+1,p))return dp[a][b]=1;
		}
	}
	return dp[a][b]=0;
}

void TC(){
	s=t="";
	cin>>s;
	int n;
	cin>>n;
	set<string> r;
	while(n--){
		cin>>t;
		memset(dp,-1,sizeof(dp));
		if(match(0,0))r.insert(t);
	}
	for(string x:r){
		cout<<x<<"\n";
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
