#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define int long long
using namespace std;
const int mod=1e9+7;
int n,m,a,b;
void quickcin(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
}
int calc(int a1,int b1,int p){
	int cnt=1;
	while(b1){
		if(b1&1){
			cnt=cnt*a1%mod;
		}
		b1>>=1;
		a1=a1*a1%mod;
	}
	return cnt;
}
int c(int m1,int n1){
	int up=1,dn=1;
	for(int i=1;i<=m1;i++){
		up=up*(n1-i+1)%mod;
		dn=dn*i%mod;
	}
	return up*calc(dn,mod-2,mod)%mod;
}
signed main(){
	quickcin();
	cin>>n>>a>>b;
	cout<<(calc(2,n,mod)-1-c(a,n)-c(b,n)+2*mod)%mod;
	return 0;
}
