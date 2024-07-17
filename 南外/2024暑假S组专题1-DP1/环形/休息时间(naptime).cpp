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
const int N=5e3+10;
using namespace std;
int n,m;
int f[5][N][2];//f[i][j][1]指前i个小时休息了j小时，且第i个小时正在休息|[0]未休息
int a[N*2];
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo init(){
	memset(f,-0x3f,sizeof(f));
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[n+i]=a[i];
	}
	//1
	init();
	f[1][0][0]=f[1][1][1]=0;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i;j++){
			f[i&1][j][0]=max(f[i-1&1][j][0],f[i-1&1][j][1]);
			if(j>=1)f[i&1][j][1]=max(f[i-1&1][j-1][0],f[i-1&1][j-1][1]+a[i]);
		}
	}
	ans=max(ans,max(f[n&1][m][1],f[n&1][m][0]));
	//2
	init();
	f[1][1][1]=a[1];
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i;j++){
			f[i&1][j][0]=max(f[i-1&1][j][0],f[i-1&1][j][1]);
			if(j>=1)f[i&1][j][1]=max(f[i-1&1][j-1][0],f[i-1&1][j-1][1]+a[i]);
		}
	}
	ans=max(ans,f[n&1][m][1]);
	cout<<ans;
	return 0;
}
/*
*/
