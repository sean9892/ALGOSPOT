#include<bits/stdc++.h>
using namespace std;

const int nmax=100010;

int seg[nmax<<2];

void upd(int idx,int l,int r,int p,int v){
	if(l>p||r<p)return;
	if(l==r){
		seg[idx]=v;
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	upd(le,l,m,p,v);upd(ri,m+1,r,p,v);
	seg[idx]=max(seg[le],seg[ri]);
}

int query(int idx,int l,int r,int s,int e){
	if(l>e||r<s)return 0;
	if(s<=l&&r<=e)return seg[idx];
	int m=l+r>>1,le=idx<<1,ri=le|1;
	return max(query(le,l,m,s,e),query(ri,m+1,r,s,e));
}

void TC(){
	memset(seg,0,sizeof(seg));
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x!=1){
			int r=query(1,1,nmax,1,x-1);
			upd(1,1,nmax,x,r+1);
		}
		else{
			upd(1,1,nmax,x,1);
		}
	}
	cout<<query(1,1,nmax,1,nmax)<<"\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
