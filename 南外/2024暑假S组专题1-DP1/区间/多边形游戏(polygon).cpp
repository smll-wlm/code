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
int ans;
int cnt1,cnt2;
int a[N],c[N];
int f[N][N][2];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void iin(){
	cin>>n;
	for(int i=1;i<=2*n;i++){
		char op;int x;
		if(i&1){
			cin>>op;
			c[++cnt2]= op=='t'? 1:2;
		}
		else{
			cin>>x;
			a[++cnt1]=x;
		}
	}
}
void init(){
	for(int i=cnt1+1;i<=n*2;i++){
		a[i]=a[i-cnt1];
	}
	for(int i=cnt2+1;i<n*2;i++){
		c[i]=c[i-cnt2];
	}
	for(int i=1;i<=n*2;i++){
		for(int j=1;j<=n*2;j++){
			f[i][j][0]=-0x3f;
			f[i][j][1]=0x3f;
		}
	}
	for(int i=1;i<=2*n;i++){
		f[i][i][0]=f[i][i][1]=a[i];
	}
}
void solve(){
	for(int len=2;len<=n;len++){
		for(int l=1;l<=n*2-len+1;l++){
			int r=l+len-1;
			for(int k=l;k<r;k++){
				if(c[k+1]==1){//+
					f[l][r][0]=max(f[l][r][0],f[l][k][0]+f[k+1][r][0]);
					f[l][r][1]=min(f[l][r][1],f[l][k][1]+f[k+1][r][1]);
				}
				else{
					for(int p=0;p<=1;p++){
						for(int q=0;q<=1;q++){
							f[l][r][0]=max(f[l][r][0],f[l][k][p]*f[k+1][r][q]);
							f[l][r][1]=min(f[l][r][1],f[l][k][p]*f[k+1][r][q]);
						}
					}
				}
			}
			
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i][i+n-1][0]);
	}
}
void out(){
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++){
		if(ans==f[i][i+n-1][0]){
			cout<<i<<' ';
		}
	}
}
signed main(){
	qui();
	iin();
	init();
	solve();
	out();
	return 0;
}
/*
*/
