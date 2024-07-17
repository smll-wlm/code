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
const int N=5e2+10;
using namespace std;
int n,m;
int f[N][N];
int v[N];
int a[N];
vector<int> son[N];
int ans,root;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo dp(int x){
	f[x][0]=0;
	for(auto it:son[x]){
		dp(it);
		for(int i=m;i>=0;i--){
			for(int j=i;j>=0;j--){
				if(i-j>=0){
					f[x][i]=max(f[x][i],f[x][i-j]+f[it][j]);
				}
			}
		}
	}
	if(x!=0){
		for(int i=m;i>0;i--){
			f[x][i]=f[x][i-1]+a[x];
		}
	}
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		a[i]=y;
		son[x].push_back(i);
	}
	dp(0);
	cout<<f[0][m];
	return 0;
}
/*
*/
