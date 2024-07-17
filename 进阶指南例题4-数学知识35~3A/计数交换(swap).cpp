#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define pii pair<int,int>
// #define int long long
#define ll long long 
#define in_vo inline void
#define in_ll inline long long
const int N=1e5+10;
const int mod=1e9+9;
using namespace std;
int n,m;
ll fc[N],f[N],f1[N];
ll ans;
int cnt,l[N],p[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll calc(ll a,ll b){
	if(b<0)return 1;
	ll aa=1;
	while(b){
		if(b&1){
			aa=aa*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return aa;
}
in_vo init(){
	fc[0]=1;
	for(int i=1;i<N;i++){
		fc[i]=fc[i-1]*i%mod;
	}
	f[1]=1;
	for(int i=2;i<N;i++){
		f[i]=calc(i,i-2);
	}
	for(int i=0;i<N;i++){
		f1[i]=calc(fc[i],mod-2)%mod;
	}
}
in_vo dfs(){
	for(int i=1;i<=n;i++){
		if(p[i]==0)continue;
		int j=i,z;
		l[++cnt]=0;
		while(p[j]!=0){
			z=p[j];
			p[j]=0;
			j=z;
			l[cnt]++;
		}
	}
	return;
}
signed main(){
	qui();
	init();
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>p[i];
		}
		dfs();
		ans=fc[n-cnt]%mod;
		// for(int i=1;i<=cnt;i++){
		// 	ans=ans*calc(l[i],l[i]-2)%mod;
		// }
		// for(int i=1;i<=cnt;i++){
		// 	ans=ans*f1[l[i]-1]%mod;
		// }
		for(int i=1;i<=cnt;i++){
			ans=ans*f1[l[i]-1]%mod*f[l[i]]%mod;
		}
		// for(int i=1;i<=cnt;i++){
		//     int inv=calc(fc[l[i]-1],mod-2);
		//     ans=ans*f[l[i]]%mod*inv%mod;
		// }
		cout<<ans<<endl;
	}
	return 0;
}
/*
*/
