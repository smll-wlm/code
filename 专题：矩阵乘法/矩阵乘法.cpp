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
int n,m,p,q,r;
int a[N][N],b[N][N],c[N][N];
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo mul(){
	memset(c,0,sizeof(c));
	for(int k=1;k<=m;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=p;j++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	// memcpy(a,c,sizeof(c));
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	cin>>m>>p;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=p;j++){
			cin>>b[i][j];
		}
	}
	mul();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=p;j++){
			cout<<c[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
/*
*/
