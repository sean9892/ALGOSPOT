#include<bits/stdc++.h>
using namespace std;

char mat[256];

void TC(){
	string s;
	cin>>s;
	stack<char> st;
	for(char x:s){
		if(mat[x]){
			if(st.empty()||st.top()!=mat[x]){
				cout<<"NO\n";
				return;
			}
			st.pop();
		}
		else{
			st.push(x);
		}
	}
	if(st.empty())cout<<"YES\n";
	else cout<<"NO\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	mat[')']='(';
	mat['}']='{';
	mat[']']='[';
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
