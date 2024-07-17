#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define pii pair<int,int>
// #define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=3e3+10;
using namespace std;
int n,m;
int f[N][N];
int a[N],b[N];
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
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int val=1;
		for(int j=1;j<=n;j++){
			f[i][j]=f[i-1][j];
			if(a[i]==b[j])f[i][j]=max(val,f[i][j]);
			if(b[j]<a[i])val=max(val,f[i-1][j]+1);
		}
	}
	
	for(int i=1;i<=n;i++){
		ans=max(ans,f[n][i]);
	}
	cout<<ans;
	return 0;
}
/*
*/
