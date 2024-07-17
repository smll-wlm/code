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
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=2e3+10;
using namespace std;
int n,m;
int ans;
int a[N],f[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=-1e18;
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			f[j]=max(f[j],f[j-1]+j*a[i]);
		}
	}
	cout<<f[m];
	return 0;
}
/*
*/
