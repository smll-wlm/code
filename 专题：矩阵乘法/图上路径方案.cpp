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
const int N=50;
const int mod=10007;
using namespace std;
int n,m,k,cnt,s,t;
int a[N][N],f[N][N];
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo mul(){
	int c[N][N];
	memset(c,0,sizeof(c));
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				c[i][j]=(c[i][j]+(int)f[i][k]*a[k][j])%mod;
			}
		}
	}
	memcpy(f,c,sizeof(c));
}
in_vo mul_self(){
	int c[N][N];
	memset(c,0,sizeof(c));
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				c[i][j]=(c[i][j]+(int)a[i][k]*a[k][j])%mod;
			}
		}
	}
	memcpy(a,c,sizeof(c));
}
signed main(){
	qui();
	cin>>n>>s>>t>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	memcpy(f,a,sizeof(a));
	m--;
	for(;m;m>>=1){
		if(m&1)mul();
		mul_self();
	}
	cout<<f[s-1][t-1];
	return 0;
}
/*
*/
