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
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x, y) memset(x, y, sizeof(x))
const int N = 1e5 + 10;
using namespace std;
int n, m;
int ans;
int a[25];
int c[N],s[N],f[1<<25],p[25][N];
void qui() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
signed main() {
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
		s[i]=s[i-1]+c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			p[i][j]=(upper_bound(s+1,s+1+m,a[i]+s[j])-s)-1;
		}
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<=n;j++){
			if(((i>>j)&1)==1){
				continue;
			}
			f[i+(1<<j)]=max(f[i+(1<<j)],p[j+1][f[i]]);
		}
	}
	ans=-1;
	for(int i=0;i<(1<<n);i++){
		if(f[i]==m){
			int res=0;
			for(int j=0;j<=n;j++){
				if(!((i>>j)&1))res+=a[j+1];
			}
			ans=max(ans,res);
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
