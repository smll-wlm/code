#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include <cassert>
#define pii pair<int,int>
#define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=4e3+10;
const int mod=2147483648;
using namespace std;
int n,m;
int ans;
int a[N];
int f[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=n;j++){
			f[j]=(f[j]+f[j-i])%mod;
		}
	}
	cout<<(f[n]-1+mod)%mod;
	return 0;
}
/*
*/
