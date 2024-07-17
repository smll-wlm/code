#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
#include <bitset>
#include <iomanip>
#define pii pair<int,int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
const int N = 1e2 + 10;
using namespace std;
int n, m;
int ans;
int s[1 << 12];
int f[12][1 << 12];
void qui() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
in_vo init() {
	mem(f, 0);
	mem(s, 0);
	f[0][0] = 1;
}
signed main() {
	qui();
	while (1) {
		cin >> n >> m;
		init();
		if (n == 0 && m == 0)return 0;
		for (int i = 0; i < 1 << m; i++) {
			bool cnt = 0, has_odd = 0;
			for (int j = 0; j < m; j++) {
				if (i >> j & 1) {
					has_odd |= cnt;
					cnt = 0;
				} else {
					cnt ^= 1;
				}
			}
			s[i] = has_odd | cnt ? 0 : 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 1 << m; j++) {
				f[i][j] = 0;
				for (int k = 0; k < 1 << m; k++) {
					if ((j & k) == 0 && s[j | k]) {
						f[i][j] += f[i - 1][k];
					}
				}
			}
		}
		cout << f[n][0] << '\n';
	}
	return 0;
}
/*
优化：
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<bitset>
#include <iomanip>
#define pii pair<int,int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
const int N=2e4+10;
using namespace std;
int n,m;
int ans,cnt;
int f1[N],f2[N];
int f[12][1<<12];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo init(){
	mem(f,0);
	cnt=0;
	f[0][0]=1;
}
in_vo dfs(int step,int s,int t){
	if(step==m){
		f1[++cnt]=s;f2[cnt]=t;
		return;
	}
	if(step>m)return;
	dfs(step+1,s<<1,t<<1|1);
	dfs(step+1,s<<1|1,t<<1);
	dfs(step+2,s<<2,t<<2);
}
signed main(){
	qui();
	while(1){
		cin>>n>>m;
		if(n==0&&m==0)return 0;
		if(n*m%2==1){
			cout<<0<<'\n';
			continue;
		}
		if(n<m)swap(n,m);
		init();
		dfs(0,0,0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=cnt;j++){
				f[i][f2[j]]+=f[i-1][f1[j]];
			}
		}
		cout<<f[n][0]<<'\n';
	}
	return 0;
}
*/
