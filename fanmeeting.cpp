#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
using cpx = complex<double>;
using poly = vector<cpx>;

void fft(poly& pol,cpx w){
	int n=pol.size();
	if(n==1)return;
	
	int i;
	
	poly e(n>>1), o(n>>1);
	for(i=0;i<n;++i){
		((i&1)?o:e)[i>>1]=pol[i];
	}
	
	fft(e,w*w);fft(o,w*w);
	
	cpx p(1,0);
	for(i=0;i<(n>>1);++i){
		pol[i]=e[i]+p*o[i];
		pol[i+(n>>1)]=e[i]-p*o[i];
		p*=w;
	}
}

poly mult(poly a,poly b){
	int n=1;
	for(;n<a.size()+1||n<b.size()+1;n<<=1);
	n<<=1;
	a.resize(n);
	b.resize(n);
	poly c(n);
	
	cpx w(cos(2*PI/n),sin(2*PI/n));
	
	fft(a,w);fft(b,w);
	
	int i=0;
	
	for(i=0;i<n;++i){
		c[i]=a[i]*b[i];
	}
	
	fft(c,cpx(1,0)/w);
	for(i=0;i<n;++i){
		c[i]/=cpx(n,0);
		c[i]=cpx(round(c[i].real()),round(c[i].imag()));
	}
	
	return c;
}

void TC(){
	string as,bs;
	cin>>as>>bs;
	poly a(as.size()),b(bs.size());
	for(int i=0;i<as.size();i++)a[i]=(as[i]=='M');
	for(int i=0;i<bs.size();i++)b[bs.size()-i-1]=(bs[i]=='M');
	poly r=mult(a,b);
	int cnt=0;
	for(int i=as.size()-1;i<bs.size();i++){
		if((int)round(r[i].real())==0)cnt++;
	}
	cout<<cnt<<"\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
