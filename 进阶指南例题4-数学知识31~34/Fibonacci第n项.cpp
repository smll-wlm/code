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
const int N=1e6+10;
using namespace std;
int n,m,k,cnt,mod;
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo mul(int f[2],int a[2][2]){
	int c[2];
	memset(c,0,sizeof(c));
	for(int j=0;j<2;j++){
		for(int k=0;k<2;k++){
			c[j]=(c[j]+(int)f[k]*a[k][j])%mod;
		}
	}
	memcpy(f,c,sizeof(c));
}
in_vo mul_self(int a[2][2]){
	int c[2][2];
	memset(c,0,sizeof(c));
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				c[i][j]=(c[i][j]+(int)a[i][k]*a[k][j])%mod;
			}
		}
	}
	memcpy(a,c,sizeof(c));
}
signed main(){
	qui();
	cin>>n>>m;
	mod=m;
	int f[2]={0,1};
	int a[2][2]={{0,1},{1,1}};
	for(;n;n>>=1){
		if(n&1)mul(f,a);
		mul_self(a);
	}
	cout<<f[0];
	return 0;
}
/*
*/
