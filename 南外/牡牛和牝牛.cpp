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
const int N=2e5+10;
const int mod=5000011;
using namespace std;
int n,m;
int ans;
int inv[N],fc[N];
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
	inv[0]=1;fc[0]=1;
	for(int i=1;i<=n;i++){
		fc[i]=fc[i-1]*i%mod;
		inv[i]=inv[i-1]*qp(i,mod-2)%mod;
	}
}
signed main(){
	qui();
	cin>>n>>m;
	init();
	int mx=(n+m)/(m+1);
	for(int i=0;i<=mx;i++){
		ans=(ans+C(n-(i-1)*m,i)%mod)%mod;
	}
	if(m)ans+=1;
	cout<<ans;
	return 0;
}

