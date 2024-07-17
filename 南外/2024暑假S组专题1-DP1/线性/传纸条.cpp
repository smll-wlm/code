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
const int N=50+10;
using namespace std;
int n,m;
int ma[N][N];
int ans,fl;
int f[N*2][N][N];
int fx[5]={0,1,0,1,0},fy[5]={0,0,1,1,0};
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ma[i][j];
		}
	}
	memset(f,0,sizeof(f));
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n&&i<=k;i++){
			for(int j=1;j<=n&&j<=k;j++){
				for(int l=1;l<=4;l++){
					if(i!=j||k==n+m||k==1){
						f[k][i][j]=max(f[k][i][j],f[k-1][i-fx[l]][j-fy[l]]+ma[i][k-i]+ma[j][k-j]);
					}
				}
			}
		}
	}
	cout<<f[n+m][n][n];
	return 0;
}
/*
*/
