#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include <cassert>
#define pii pair<int,int>
#define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=1e2+10;
using namespace std;
int n,m;
int ans;
int a[N];
int f[N][10010];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			f[i][j]=f[i-1][j];
		}
		for(int j=a[i];j<=m;j++){
			f[i][j]+=f[i-1][j-a[i]];
		}
	}
	cout<<f[n][m];
	return 0;
}
/*
*/
