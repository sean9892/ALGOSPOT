#include<bits/stdc++.h>
using namespace std;

int a[20010];

int f(int l,int r){
	if(l==r)return a[l];
	int m=l+r>>1;
	int x=f(l,m),y=f(m+1,r);
	int le=m,ri=m+1;
	int mn=min(a[m],a[m+1]);
	int mx=mn*2;
	while(le!=l||ri!=r){
		if(le==l)mn=min(mn,a[++ri]);
		else if(ri==r)mn=min(mn,a[--le]);
		else{
			if(a[le-1]<a[ri+1])mn=min(mn,a[++ri]);
			else mn=min(mn,a[--le]);
		}
		mx=max(mx,mn*(ri-le+1));
	}
	return max({x,mx,y});
}

void TC(){
	memset(a,0,sizeof(a));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<f(1,n)<<"\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
