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
const int mod=1e9;
using namespace std;
int n,m;
int ans;
string s;
int a[N];
int f[N][N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>s;
	n=s.size();
	for(int i=1;i<=s.size();i++){
		a[i]=s[i-1]-'A'+1;
	}
	for(int i=1;i<=n;i++){
		f[i][i]=1;
	}
	for(int len=2;len<=n;len++){
		for(int l=1;l<=n-len+1;l++){
			int r=l+len-1;
			if(a[l]==a[r]){
				int res=0;
				for(int k=l+2;k<=r-2;k++){
					res+=f[l+1][k-1]*f[k][r];
					res%=mod;
				}
				f[l][r]=(f[l+1][r-1]+res)%mod;
			}
			else{
				f[l][r]=0;
			}
		}
	}
	cout<<f[1][n]%mod;
	return 0;
}
/*
*/
