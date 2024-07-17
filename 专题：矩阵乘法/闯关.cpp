#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=50+10;
const int mod=10007;
using namespace std;
int n,m,k,cnt,s,t;
int a[N][N],f[N][N];
int c[N][N];
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo mul(){
	memset(c,0,sizeof(c));
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				c[i][j]=(c[i][j]+f[i][k]*a[k][j]%mod)%mod;
			}
		}
	}
	memcpy(f,c,sizeof(c));
}
in_vo mul_self(){
	memset(c,0,sizeof(c));
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				c[i][j]=(c[i][j]+a[i][k]*a[k][j]%mod)%mod;
			}
		}
	}
	memcpy(a,c,sizeof(c));
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(i==j)f[i][j]=1;
		}
	}
	cin>>s>>t;
	for(;m;m>>=1){
		if(m&1)mul();
		mul_self();
	}
	cout<<f[s][t];
	return 0;
}
/*
*/
