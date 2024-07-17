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
int f[10010];
int w[N],v[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>t>>n>>m;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];//i天第j个物品价格
		}
	}
	for(int i=2;i<=t;i++){
		memset(f,0,sizeof(f));
		for(int j=1;j<=n;j++){
			w[j]=a[i][j]-a[i-1][j];
			v[j]=a[i-1][j];
		}
		for(int j=1;j<=n;j++){
			for(int k=v[j];k<=m;k++){
				f[k]=max(f[k],f[k-v[j]]+w[j]);
			}
		}
		m+=f[m];
	}
	cout<<m;
	return 0;
}
