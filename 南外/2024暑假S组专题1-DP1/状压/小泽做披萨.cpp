#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
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
int ans;
int f[1<<21];
int ma[21][21];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main()
{
	qui();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		ma[x][y]=1;
		ma[y][x]=1;
	}
	f[0]=1;
	for(int i=0;i<(1<<n);i++){
		if(f[i]==0)continue;
		for(int j=0;j<n;j++){
			if(((i>>j)&1)==1)continue;
			int fl=0;
			for(int k=0;k<n;k++){
				if(ma[k+1][j+1]==1&&((i>>k)&1)==1){
					fl=1;
					break;
				}
			}
			if(fl==0)f[i+(1<<j)]=1;
		}
	}
	// for(int i=0;i<(1<<n);i++){
	//     cout<<f[i]<<' ';
	// }
	for(int i=0;i<(1<<n);i++){
		ans+=f[i];
	}
	cout<<ans;
	return 0;
}
