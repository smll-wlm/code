#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include<string>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
#define pii pair<int, int>
#define y1 y114514
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=2e5+10;
int n,m;
int ans,midd;
struct node{
	int to,wa,wb;
};
vector<node> v[N];
int f[N][30],sz[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo dfs(int x,int pre){
	f[x][0]=0;
	sz[x]=0;
	for(auto [y,a,b]:v[x]){
		if(y==pre)continue;
		dfs(y,x);
		int g[30];
		for(int i=0;i<=min(m,sz[x]+sz[y]+1);i++){
			g[i]=midd+1;
		}
		for(int i=0;i<=sz[x];i++){
			for(int j=0;j<=min(sz[y],m-i);j++){
				if(f[x][i]+f[y][j]+a<=midd){
					g[i+j+1]=min(g[i+j+1],max(f[x][i],f[y][j]+a));
				}
				if(f[x][i]+f[y][j]+b<=midd){
					g[i+j]=min(g[i+j],max(f[x][i],f[y][j]+b));
				}
			}
		}
		sz[x]=min(sz[x]+sz[y]+1,m);
		for(int i=0;i<=sz[x];i++){
			f[x][i]=g[i];
		}
	}
}
in_vo init(){
	for(int i=0;i<=n+1;i++){
		v[i].clear();
	}
}
signed main()
{
	qui();
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		init();
		int l=1,r=1e14+10;
		for(int i=1;i<n;i++){
			int x,y,wa,wb;
			cin>>x>>y>>wa>>wb;
			v[x].push_back({y,wa,wb});
			v[y].push_back({x,wa,wb});
		}
		ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			midd=mid;
			dfs(1,0);
			if(f[1][m]==mid+1){
				l=mid+1;
			}
			else{
				r=mid-1;
				ans=mid;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
