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
#define in_vo inline void
#define in_ll inline long long
const int N=2e2+10;
using namespace std;
int n,m;
int ma[N][N];
int q[1010];
int ans,fl;
int f[2][210][210];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>ma[i][j];
		}
	}
	for(int i=1;i<=m;i++)cin>>q[i];
	memset(f,0x3f,sizeof(f));
	f[0][1][2]=0;
	q[0]=3;
	for(int i=0;i<m;i++,fl^=1){
		memset(f[fl^1],0x3f,sizeof(f[fl^1]));
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				int z=q[i],x=j,y=k;
				if(x!=q[i+1]&&y!=q[i+1])
					f[fl^1][x][y]=min(f[fl^1][x][y],f[fl][x][y]+ma[z][q[i+1]]);
				if(q[i+1]!=z&&q[i+1]!=y)
					f[fl^1][y][z]=min(f[fl^1][y][z],f[fl][x][y]+ma[x][q[i+1]]);
				if(x!=q[i+1]&&q[i+1]!=z)
					f[fl^1][x][z]=min(f[fl^1][x][z],f[fl][x][y]+ma[y][q[i+1]]);
			}
		}
	}
	ans=1e9;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=min(ans,f[m&1][i][j]);
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
