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
const int N=1e3+10;
using namespace std;
int n,m;
int t;
int a[N][N];
int f[N][N][2];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	memset(f,-0x3f,sizeof(f));
	f[1][1][0]=f[1][1][1]=a[1][1];
	for(int i=2;i<=n;++i)f[i][1][0]=f[i-1][1][0]+a[i][1];
	for(int j=2;j<=m;j++){
		for(int i=1;i<=n;++i)
			f[i][j][0]=f[i][j][1]=max(f[i][j-1][0],f[i][j-1][1])+a[i][j];
		for(int i=2;i<=n;i++){
			f[i][j][0]=max(f[i][j][0],f[i-1][j][0]+a[i][j]);
		}
		for(int i=n-1;i>=1;i--){
			f[i][j][1]=max(f[i][j][1],f[i+1][j][1]+a[i][j]);
		}
		
	}
	
	cout<<max(f[n][m][0],f[n][m][1]);
	return 0;
}
