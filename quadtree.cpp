#include<bits/stdc++.h>
using namespace std;

int tree[1010][4];
const int c[]={2,3,0,1};

int p;
string s;
void build(){
	int idx=p;
	++p;
	if(s[idx]=='x'){
		for(int i=0;i<4;i++){
			tree[idx][i]=p;
			build();
		}
	}
}
void pr(int idx){
	cout<<s[idx];
	if(s[idx]=='x'){
		for(int i=0;i<4;i++){
			pr(tree[idx][c[i]]);
		}
	}
}

void TC(){
	p=0;
	memset(tree,0,sizeof(tree));
	cin>>s;
	build();
	pr(0);
	cout<<"\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
