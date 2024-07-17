#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<bitset>
#define pii pair<int,int>
#define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=5e5+10;
using namespace std;
int n,m;
int f[N];
int v[N];
int deg[N],d[N];
int ne[N],he[N],ed[N],to[N],tot;
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo add(int x,int y,int z){
	to[tot]=y;
	ed[tot]=z;
	ne[tot]=he[x];
	he[x]=tot++;
}
in_vo dfs(int x){
	v[x]=1;
	for(int i=he[x];i!=-1;i=ne[i]){
		int y=to[i];
		if(v[y])continue;
		if(deg[x]==1)f[y]=d[y]+ed[i];
		else if(deg[y]==1) f[y] = d[y] + min(f[x] - ed[i], ed[i]);
		else f[y] = d[y] + min(f[x] - min(d[y], ed[i]), ed[i]);
		dfs(y);
	}
}
in_vo dp(int x){
	v[x]=1;
	d[x]=0;
	for(int i=he[x];i!=-1;i=ne[i]){
		int y=to[i];
		if(v[y])continue;
		dp(y);
		if(deg[y]==1)d[x]+=ed[i];
		else d[x]+=min(d[y],ed[i]);
	}
}
in_vo init(){
	memset(v,0,sizeof(v));
	memset(he,-1,sizeof(he));
	memset(ne,-1,sizeof(ne));
	memset(to,0,sizeof(to));
	memset(ed,0,sizeof(ed));
	memset(f,0,sizeof(f));
	memset(d,0,sizeof(d));
	memset(deg,0,sizeof(deg));
	ans=0;
	tot=0;
}
signed main(){
	qui();
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		init();
		for(int i=1;i<n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			deg[x]++;deg[y]++;
			add(x,y,z);add(y,x,z);
		}
		int root=1;
		dp(root);
		memset(v,0,sizeof(v));
		f[root]=d[root];
		dfs(root);
		for(int i=1;i<=n;i++){
			ans=max(ans,f[i]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
*/
