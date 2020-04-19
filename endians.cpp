#include<bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		uint x;
		cin>>x;
		uint r=0;
		for(int i=0;i<32;i+=8){
			uint t=x&(255<<i);
			t>>=i;
			t<<=24-i;
			r|=t;
		}
		cout<<r<<"\n";
	}
}
