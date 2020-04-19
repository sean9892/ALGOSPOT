#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int los[1000010<<2];
int his[1000010<<2];

void upd(int idx,int l,int r,int p,int v){
	if(l>p||r<p)return;
	if(l==r){
		los[idx]=his[idx]=v;
		return;
	}
	int m=l+r>>1,le=idx<<1,ri=le|1;
	upd(le,l,m,p,v);upd(ri,m+1,r,p,v);
	los[idx]=min(los[le],los[ri]);
	his[idx]=max(his[le],his[ri]);
}

const int inf=0x3f3f3f3f;
pii query(int idx,int l,int r,int s,int e){
	if(l>e||r<s)return pii(inf,-inf);
	if(s<=l&&r<=e)return pii(los[idx],his[idx]);
	int m=l+r>>1,le=idx<<1,ri=le|1;
	pii x=query(le,l,m,s,e),y=query(ri,m+1,r,s,e);
	return pii(min(x.first,y.first),max(x.second,y.second));
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0')upd(1,0,s.size()-1,i,1);
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);
		pii r=query(1,0,s.size()-1,a,b);
		if(r.first==r.second)cout<<"Yes\n";
		else cout<<"No\n";
	}
}
