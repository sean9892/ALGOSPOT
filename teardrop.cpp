#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int nmax=1e5+10;
ll seg[nmax<<2];
ll lazy[nmax<<2];

void prop(int idx,int l,int r){
	if(lazy[idx]==0)return;
	seg[idx]+=(r-l+1)*lazy[idx];
	if(l!=r){
		int le=idx<<1,ri=le|1;
		lazy[le]+=lazy[idx];
		lazy[ri]+=lazy[idx];
	}
	lazy[idx]=0;
}

void upd(int idx,int l,int r,int s,int e,ll x){
	prop(idx,l,r);
	if(l>e||r<s)return;
	if(s<=l&&r<=e){
		lazy[idx]=x;
		prop(idx,l,r);
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	upd(le,l,m,s,e,x);upd(ri,m+1,r,s,e,x);
	seg[idx]=seg[le]+seg[ri];
}

ll get(int idx,int l,int r,int s,int e){
	prop(idx,l,r);
	if(l>e||r<s)return 0;
	if(s<=l&&r<=e)return seg[idx];
	int m=l+r>>1,le=idx<<1,ri=le|1;
	return get(le,l,m,s,e)+get(ri,m+1,r,s,e);
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	ll ini=0;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		upd(1,0,n,0,i,-x);
		upd(1,0,n,i+1,n,+x);
		ini+=i*x;
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int x;
		cin>>x;
		if(x<=0){
			cout<<ini-x*get(1,0,n,0,0)<<"\n";
		}
		else if(x>=n){
			cout<<ini+get(1,0,n,1,n-1)+get(1,0,n,n,n)*(x-n+1)<<"\n";
		}
		else{
			cout<<ini+get(1,0,n,1,x)<<"\n";
		}
	}
}
