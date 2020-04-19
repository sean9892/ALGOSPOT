#include<bits/stdc++.h>
using namespace std;

int c[1010];
int s[1010];
void TC(){
	memset(c,0,sizeof(c));
	memset(s,0,sizeof(s));
	int n,l;
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
		s[i]=s[i-1]+c[i];
	}
	double m=1e9;
	for(int i=l;i<=n;i++){
		for(int j=i-l;j>=0;j--){
			double r=1.*(s[i]-s[j])/(i-j);
			m=min(m,r);
		}
	}
	printf("%.9lf\n",m);
}

int main(void){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		TC();
	}
}
