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
int k;
int f[1<<20],a[20][20];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main()
{
	qui();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	mem(f,0x3f);f[0]=0;
	for(int i=0;i<(1<<n);i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(((i>>j)&1)==0){
				continue;
			}
			for(int l=j+1;l<n;l++){
				if(((i>>l)&1) &&a[j+1][l+1]==1){
					++cnt;
				}
			}
		}
		if(cnt<=k){
			f[i]=1;
		}
		else{
			for(int j=i;j;j=(j-1)&i){
				f[i]=min(f[i],f[i^j]+f[j]);
			}
		}
	}
	cout<<f[(1<<n)-1];
	return 0;
}
