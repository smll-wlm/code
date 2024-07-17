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
const int N=4e3+10;
const int mod=2147483648;
using namespace std;
int n,m;
int ans;
int a[N],sum[N];
int f[N][N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		f[i][i]=0;
	}
	for(int i=2;i<=n;i++){
		for(int l=1;l<=n-i+1;l++){
			int r=i+l-1;
			for(int j=l;j<=r;j++){
				f[l][r]=min(f[l][r],f[l][j]+f[j+1][r]);
			}
			f[l][r]+=sum[r]-sum[l-1];
		}
	}
	cout<<f[1][n];
	return 0;
}
/*
*/
