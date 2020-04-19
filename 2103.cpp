#include<bits/stdc++.h>
using namespace std;
using psi=pair<string,int>;

int mem[2000010];

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	queue<psi> q;
	q.push(psi("1",1));
	mem[1]=1;
	while(!q.empty()){
		string s=q.front().first;
		int r=q.front().second;
		q.pop();
		int t=r*10%n;
		if(!mem[t]){
			if(t==0){
				cout<<s<<"0";
				return 0;
			}
			mem[t]=1;
			q.push(psi(s+"0",t));
		}
		if(!mem[(t+1)%n]){
			if(t==n-1){
				cout<<s<<"1";
				return 0;
			}
			mem[(t+1)%n]=1;
			q.push(psi(s+"1",(t+1)%n));
		}
	}
}
