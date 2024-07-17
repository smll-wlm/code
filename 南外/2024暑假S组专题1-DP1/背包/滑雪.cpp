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
const int N=1e2+10;
using namespace std;
int n,m;
int k;
int ans;
int f[N][N];//f[i][j]表示从(i,j)开始
int ma[N][N];
int fx[5]={0,1,-1,0,0},fy[5]={0,0,0,1,-1};
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll solve(int x,int y){
	if(f[x][y]){
		return f[x][y];
	}
	int res=0;
	for(int i=1;i<=4;i++){
		if(x+fx[i]>=1&&x+fx[i]<=n&&y+fy[i]>=1&&y+fy[i]<=m){
			if(ma[x][y]>ma[x+fx[i]][y+fy[i]])
				res=max(res,solve(x+fx[i],y+fy[i]));
		}
	}
	return f[x][y]=res+1;
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
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!f[i][j]){
				f[i][j]=solve(i,j);
			}
			ans=max(ans,f[i][j]);
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
