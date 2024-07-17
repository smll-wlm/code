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
const int N=1e6+10;
using namespace std;
int n,m;
int e;
int si[N],fa[N];
int u[N],v[N],xx[N];
bool vis[N];
int ans[N],q;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll fi(int x){
	if(x==fa[x])return fa[x];
	return fa[x]=fi(fa[x]);
}
in_vo merge(int x,int y){
	int aa=fi(x),bb=fi(y);
	if(aa==bb)return;
	if(aa>bb)swap(aa,bb);
	si[bb]+=si[aa];fa[aa]=bb;
}
signed main(){
	qui();
	cin>>n>>m>>e;
	for(int i=1;i<=e;i++){
		int x,y;
		cin>>x>>y;
		u[i]=x;v[i]=y;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int x;
		cin>>x;
		xx[i]=x;
		vis[x]=1;
	}
	for(int i=1;i<=n+m;i++){
		fa[i]=i;
		si[i]=(i<=n);
	}
	for(int i=1;i<=e;i++){
		if(!vis[i])
			merge(u[i],v[i]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(fi(i)>n)cnt++;
	}
	for(int i=q;i>=1;i--){
		ans[i]=cnt;
		int p=xx[i];
		if(fi(u[p])<=n&&fi(v[p])>n){
			cnt+=si[fi(u[p])];
		}
		if(fi(u[p])>n&&fi(v[p])<=n){
			cnt+=si[fi(v[p])];
		}
		merge(u[p],v[p]);
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}

