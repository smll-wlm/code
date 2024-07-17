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
const int N=6;
const int mod=1e9+7;
using namespace std;
int n,m,k,cnt,s,t;
int a[6][6]={{1,1,0,0,0,0},{1,0,0,0,0,0},{1,0,1,0,0,0},
			 {3,0,3,1,0,0},{3,0,3,2,1,0},{2,0,1,1,1,1}};
int f[6]={1,1,8,4,2,1};
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo mul(){
	int c[6];
	memset(c,0,sizeof(c));
	for(int j=0;j<6;j++){
		for(int k=0;k<6;k++){
			c[j]=(c[j]+(int)f[k]*a[k][j])%mod;
		}
	}
	memcpy(f,c,sizeof(c));
}
in_vo mul_self(){
	int c[6][6];
	memset(c,0,sizeof(c));
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			for(int k=0;k<6;k++){
				c[i][j]=(c[i][j]+(int)a[i][k]*a[k][j])%mod;
			}
		}
	}
	memcpy(a,c,sizeof(c));
}
signed main(){
	qui();
	cin>>n;
	m=n-2;
	if(n<3){
		cout<<1;
		return 0;
	}
	for(;m;m>>=1){
		if(m&1)mul();
		mul_self();
	}
	cout<<f[0];
	return 0;
}
/*
f[i]=f[i-1]+f[i-2]+i^3+1
===>f[i+1]=f[i]+f[i-1]+i^3+3*i^2+3*i+2*1
>矩阵f[n]==>[f[n],f[n-1],(n+1)^3,(n+1)^2,n+1,1]
>矩阵A:{    {1,1,0,0,0,0}
			{1,0,0,0,0,0}
			{1,0,1,0,0,0}
			{3,0,3,1,0,0}
			{3,0,3,2,1,0}
			{2,0,1,1,1,1}   }
*/
