#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>; 

void TC(){
	vector<int> a,b;
	set<pii> s;
	
	for(int i=0;i<3;i++){
		int x,y;
		cin>>x>>y;
		a.push_back(x);
		b.push_back(y);
		s.insert(pii(x,y));
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int x:a){
		for(int y:b){
			if(s.find(pii(x,y))==s.end()){
				cout<<x<<" "<<y<<"\n";
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
