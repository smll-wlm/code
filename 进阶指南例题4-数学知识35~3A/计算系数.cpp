#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define pii pair<int,int>
#define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=1e4+10;
const int mod=10007;
using namespace std;
int n,m,p,q;
int a,b,k;
int ans;
int jc[N],jc_inv[N],comb[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll calc(int a1,int b1,int mod){
	int cnt=1;
	while(b1){
		if(b1&1){
			cnt=cnt*a1%mod;
		}
		a1=a1*a1%mod;
		b1>>=1;
	}
	return cnt;
}
in_vo jc1(){
	int cnt=1;
	for(int i=1;i<=k;i++){
		cnt=cnt*i%mod;
		jc[i]=cnt;
		jc_inv[i]=calc(cnt,mod-2,mod);
	}
	return;
}
in_ll combination(int x,int y){
	return jc[x]*jc_inv[y]*jc_inv[x-y]%mod;
}
signed main(){
	qui();
	cin>>a>>b>>k>>n>>m;
	int a1=calc(a,n,mod),b1=calc(b,m,mod);
	jc1();
	ans=combination(k,n)%mod*a1%mod*b1%mod;
	cout<<ans;
	return 0;
}
/*
*/
