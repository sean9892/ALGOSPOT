#include<bits/stdc++.h>
using namespace std;

vector<int> g[10];

void init(){
	g[0].push_back(0);
	g[0].push_back(1);
	g[0].push_back(2);
	g[1].push_back(3);
	g[1].push_back(7);
	g[1].push_back(9);
	g[1].push_back(11);
	g[2].push_back(4);
	g[2].push_back(10);
	g[2].push_back(14);
	g[2].push_back(15);
	g[3].push_back(0);
	g[3].push_back(4);
	g[3].push_back(5);
	g[3].push_back(6);
	g[3].push_back(7);
	g[4].push_back(6);
	g[4].push_back(7);
	g[4].push_back(8);
	g[4].push_back(10);
	g[4].push_back(12);
	g[5].push_back(0);
	g[5].push_back(2);
	g[5].push_back(14);
	g[5].push_back(15);
	g[6].push_back(3);
	g[6].push_back(14);
	g[6].push_back(15);
	g[7].push_back(4);
	g[7].push_back(5);
	g[7].push_back(7);
	g[7].push_back(14);
	g[7].push_back(15);
	g[8].push_back(1);
	g[8].push_back(2);
	g[8].push_back(3);
	g[8].push_back(4);
	g[8].push_back(5);
	g[9].push_back(3);
	g[9].push_back(4);
	g[9].push_back(5);
	g[9].push_back(9);
	g[9].push_back(13);
}
const int inf=0x3f3f3f3f;
int a[16];
int f(int d){
	if(d==10){
		for(int i=0;i<16;i++){
			if(a[i])return inf;
		}
		return 0;
	}
	for(int i=0;i<4;i++){
		int r=f(d+1);
		if(r!=inf){
			return r+i;
		}
		for(int j:g[d]){
			a[j]++;
			a[j]%=4;
		}
	}
	return inf;
}

void TC(){
	for(int i=0;i<16;i++){
		cin>>a[i];
		a[i]%=12;
		a[i]/=3;
	}
	int r=f(0);
	if(r==inf)cout<<"-1\n";
	else cout<<r<<"\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	init();
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
