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
const int N=2e3+10;
using namespace std;
int n,m;
int v,w,s,tot;
int f[N][N];
int a[N];
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=s;j>=0;j--){
			for(int k=s-j;k>=0;k--){
				if(j>=a[i]){
					f[j][k]=f[j][k]|f[j-a[i]][k];
				}
				if(k>=a[i]){
					f[j][k]=f[j][k]|f[j][k-a[i]];
				}
			}
		}
	}
	ans=1e9;
	for(int i=s;i>=0;i--){
		for(int j=s-i;j>=0;j--){
			int z=s-i-j;
			if(f[i][j]&&z>=i&&z>=j){
				ans=min(ans,z);
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
