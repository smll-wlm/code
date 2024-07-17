#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <cmath>
#define pii pair<int, int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
const int N = 1e5+10;
using namespace std;
int n,m;
int a[N],fa[N];
int f[N][25];
vector<int> v[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo dfs(int x,int pre){
	f[x][0]=a[x];
	for(auto y:v[x]){
		if(y==pre)continue;
		fa[y]=x;
		dfs(y,x);
		for(int i=0;i<m;i++){
			f[x][i+1]+=f[y][i];
		}
	}
}
signed main()
{
	qui();
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]+=f[i][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		int ans=f[i][m];
		for(int j=1,x=i;j<=m&&x!=1;j++){
			ans+=f[fa[x]][m-j]-(m==j?0:f[x][m-j-1]);
			x=fa[x];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
