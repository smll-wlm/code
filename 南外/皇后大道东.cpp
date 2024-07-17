#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <map>
#define pii pair<int, int>
// #define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x, y) memset(x, y, sizeof(x))
const int N = 755;
const int mod=1e9+7;
using namespace std;
int n, m;
int k,ans;
int ma[N][N],f[N][N],sum[N][N];
int tot,rt[N*N],ls[N*N*16],rs[N*N*16],val[N*N*16];
void qui() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo update(int &p,int l,int r,int x,int v){
	if(!p){
		p=++tot;
	}
	if(l==r){
		val[p]=(0ll+val[p]+v)%mod;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid){
		update(ls[p],l,mid,x,v);
	}
	else{
		update(rs[p],mid+1,r,x,v);
	}
	val[p]=(0ll+val[ls[p]]+val[rs[p]])%mod;
}
inline int ask(int p,int l,int r,int L,int R){
	if(!p)return 0;
	if(l<=L&&r>=R){
		return val[p];
	}
	int mid=(L+R)>>1;
	int ret=0;
	if(l<=mid){
		ret=(0ll+ret+ask(ls[p],l,r,L,mid))%mod;
	}
	if(r>mid){
		ret=(0ll+ret+ask(rs[p],l,r,mid+1,R))%mod;
	}
	return ret%mod;
}
signed main() {
	qui();
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ma[i][j];
		}
	}
	f[1][1]=sum[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1)continue;
			f[i][j]=sum[i-1][j-1];
			f[i][j]=(0ll+f[i][j]-ask(rt[ma[i][j]],1,j-1,1,n))%mod;
			sum[i][j]=(0ll+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+f[i][j])%mod;
			
		}
		for(int j=1;j<=m;j++){
			update(rt[ma[i][j]],1,n,j,f[i][j]);
		}
	}
	cout<<(f[n][m]%mod+mod)%mod<<'\n';
	return 0;
}
/*
*/
