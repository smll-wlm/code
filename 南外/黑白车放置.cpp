#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define pii pair<int,int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=510;
const int mod=998244353;
using namespace std;
int n,m;
int b,w,l;
int ans;
int inv[N*N],fc[N*N],f[N][N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll qp(int a,int b){
	int res=1;
	while(b){
		if(b&1){
			res=res*a%mod;
		}
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
in_ll C(int m1,int n1){
	if(m1<=0||n1<0||n1>m1)return 0;
	return fc[m1]*inv[n1]%mod*inv[m1-n1]%mod;
}
void init(){
	l=n*m;
	inv[0]=1;fc[0]=1;
	for(int i=1;i<=l;i++){
		fc[i]=fc[i-1]*i%mod;
		inv[i]=inv[i-1]*qp(i,mod-2)%mod;
	}
}
signed main(){
	qui();
	cin>>n>>m>>b>>w;
	init();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=i,fl=1;k>=0;k--,fl*=-1){
				f[i][j]=(f[i][j]+fl*C(i,k)*C(k*j,b)%mod)%mod;
			}
			for(int k=1;k<j;k++){
				f[i][j]=(f[i][j]-f[i][k]*C(j,k)%mod)%mod;
			}
			ans=(ans+f[i][j]*C((n-i)*(m-j),w)%mod*C(n,i)%mod*C(m,j)%mod)%mod;
		}
	}
	cout<<(ans+mod)%mod;
	return 0;
}

