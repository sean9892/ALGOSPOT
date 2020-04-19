#include<bits/stdc++.h>
using namespace std;

int h,w;
string a[20];
int arr[21][21];

int f(int x,int y){
	if(x==h)return 1;
	if(y==w)return f(x+1,0);
	if(arr[x][y])return f(x,y+1);
	int sum=0;
	if(x+1<h){
		if(y+1<w){
			if(0==arr[x+1][y]&&0==arr[x][y+1]){
				arr[x][y]=arr[x+1][y]=arr[x][y+1]=1;
				sum+=f(x,y+1);
				arr[x][y]=arr[x+1][y]=arr[x][y+1]=0;
			}
			if(0==arr[x+1][y]&&0==arr[x+1][y+1]){
				arr[x][y]=arr[x+1][y]=arr[x+1][y+1]=1;
				sum+=f(x,y+1);
				arr[x][y]=arr[x+1][y]=arr[x+1][y+1]=0;
			}
			if(0==arr[x][y+1]&&0==arr[x+1][y+1]){
				arr[x][y]=arr[x][y+1]=arr[x+1][y+1]=1;
				sum+=f(x,y+1);
				arr[x][y]=arr[x][y+1]=arr[x+1][y+1]=0;
			}
		}
		if(y){
			if(0==arr[x+1][y]&&0==arr[x+1][y-1]){
				arr[x][y]=arr[x+1][y]=arr[x+1][y-1]=1;
				sum+=f(x,y+1);
				arr[x][y]=arr[x+1][y]=arr[x+1][y-1]=0;
			}
		}
	}
	return sum;
}

void TC(){
	cin>>h>>w;
	for(int i=0;i<h;i++){
		cin>>a[i];
		for(int j=0;j<w;j++)arr[i][j]=(a[i][j]=='#');
	}
	cout<<f(0,0)<<"\n";
}

int main(void){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		TC();
	}
}
