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
const int N = 5e3+10;
using namespace std;
int n,m;
int a[N],sz[N];
int f[N][N][2];
int c[N],d[N];
vector<int> v[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo dfs(int x){
	f[x][0][0]=0;f[x][1][1]=c[x]-d[x];f[x][1][0]=c[x];
	sz[x]=1;
	for(auto y:v[x]){
		dfs(y);
		for(int i=sz[x];i>=0;i--){
			for(int j=0;j<=sz[y];j++){
				f[x][i+j][0]=min(f[x][i+j][0],f[x][i][0]+f[y][j][0]);
				f[x][i+j][1]=min(f[x][i+j][1],f[x][i][1]+min(f[y][j][0],f[y][j][1]));
			}
		}
		sz[x]+=sz[y];
	}
}
signed main()
{
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>c[i]>>d[i];
		if(i!=1){
			cin>>x;
			v[x].push_back(i);
		}
	}
	mem(f,0x3f);
	dfs(1);
	for(int i=n;i>=0;i--){
		if(f[1][i][0]<=m||f[1][i][1]<=m){
			cout<<i<<'\n';
			break;
		}
	}
	return 0;
}
