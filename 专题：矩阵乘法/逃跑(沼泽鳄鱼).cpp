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
const int mod=10000;
const int N=60;
int n,m,s,t,k,d,c[N][N];
int A[N][N][N],ans[N][N];
int base[N][N],tmp[N][N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo mul(int a[N][N],int b[N][N]){
	memset(tmp,0,sizeof(tmp));
	for(int l=0;l<n;l++){
		for(int i=0;i<n;i++){
			if(a[i][l]==0)continue;
			for(int j=0;j<n;j++){
				tmp[i][j]+=(a[i][l]*b[l][j])%mod;
				tmp[i][j]%=mod;
			}
		}
	}
	memcpy(a,tmp,sizeof(tmp));
	return;
}
void ksm(int y){
	while(y>0){
		if(y&1) mul(ans,base);
		mul(base,base);
		y>>=1;
	}
}
void init(int x,int y){
	for(int i=0;i<n;i++) A[x][i][y]=0;
}
signed main()
{
	cin>>n>>m>>s>>t>>k;
	ans[0][s]=1;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		for(int j=1;j<=12;j++)
			A[j][x][y]=A[j][y][x]=1;
	}
	cin>>d;
	for(int i=1;i<=d;i++){
		cin>>c[i][0];
		for(int j=1;j<=c[i][0];j++)
		{
			cin>>c[i][j];
		}
	}
	for(int i=0;i<=12;i++){
		for(int j=1;j<=d;j++){
			int x=c[j][0];
			int y=c[j][i%x+1];
			init(i,y);
		}
	}
	for(int i=0;i<n;i++) base[i][i]=1;
	for(int i=1;i<=12;i++) mul(base,A[i]);
	int x=k/12,y=k%12;
	ksm(x);
	for(int i=1;i<=y;i++) mul(ans,A[i]);
	cout<<ans[0][t];
	return 0;
}
