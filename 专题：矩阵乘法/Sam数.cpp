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
const int N=100;
const int mod=1e9+7;
using namespace std;
int n=10,m,k,cnt,s,t;
int f[N][N];
int	a[N][N]=
{ 	{1,1,1,0,0,0,0,0,0,0},
	{1,1,1,1,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0},
	{0,1,1,1,1,1,0,0,0,0},
	{0,0,1,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,1,0,0},
	{0,0,0,0,1,1,1,1,1,0},
	{0,0,0,0,0,1,1,1,1,1},
	{0,0,0,0,0,0,1,1,1,1},
	{0,0,0,0,0,0,0,1,1,1} };
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
	cin>>m;
	if(m==1){
		cout<<10;
		return 0;
	}
	m--;
	for(int i=1;i<n;i++)f[0][i]=1;
	for(;m;m>>=1){
		if(m&1)mul();
		mul_self();
	}
	for(int i=0;i<n;i++){
		ans+=f[0][i]%mod;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
/*
*/
