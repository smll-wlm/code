#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define fir first
#define sec second
#define int long long
#define in_vo inline void
#define in_ll inline long long
using namespace std;
const int N=20;
int n,m;
int ans,f[N][N][N][N];
int a[N][N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main()
{
	qui();
	cin>>n;
	while(1){
		int x,y,w;
		cin>>x>>y>>w;
		if(x==y&&y==w&&w==0)break;
		a[x][y]=w;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++){
					f[i][j][k][l]=max(max(f[i-1][j][k-1][l],f[i][j-1][k-1][l]),max(f[i-1][j][k][l-1],f[i][j-1][k][l-1]))+a[i][j]+a[k][l];
					if(i==k&&j==l){
						f[i][j][k][l]-=a[i][j];
					}
				}
			}
		}
	}
	cout<<f[n][n][n][n];
	return 0;
}
