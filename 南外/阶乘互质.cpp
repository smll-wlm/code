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
#define ll long long 
#define in_vo inline void
#define in_ll inline long long
const int N=1e7+10;
using namespace std;
int n,m;
int f[N],phi[N];
bool v[N];
int mod;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll calc(int a,int b){
	int cnt=1;
	while(b){
		if(b&1){
			cnt=cnt*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return cnt;
}
void get_phi(){
	f[1]=1;phi[1]=1;
	for(int i=2;i<=N;i++){
		f[i]=f[i-1]*i%mod;
	}
	for(int i=2;i<=N;i++){
		if(!v[i]){
			for(int j=2*i;j<=N;j+=i){
				v[j]=1;
			}
		}
	}
	for(int i=2;i<=N;i++){
		if(!v[i]){
			phi[i]=phi[i-1]*calc(i,mod-2)%mod*(i-1)%mod;
		}
		else{
			phi[i]=phi[i-1];
		}
	}
}
signed main(){
	qui();
	int T;
	cin>>T>>mod;
	get_phi();
	while(T--){
		cin>>n>>m;
		cout<<f[n]*phi[m]%mod<<endl;
	}
	return 0;
}
/*
*/
