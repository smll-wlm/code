#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <cmath>
#define pii pair<int, int>
// #define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
const int N = 5e3+10;
using namespace std;
int n,m;
int ans;
string s;
int a[N];
int f[N][N],g[N][N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main()
{
	qui();
	cin>>s;
	cin>>n;
	m=s.size();
	for(int i=1;i<=m+1;i++){
		f[i][i]=f[i][i-1]=1;
	}
	for(int len=2;len<=m;len++){
		for(int i=1;i+len-1<=m;i++){
			int j=i+len-1;
			if(s[i-1]==s[j-1]){
				f[i][j]=f[i+1][j-1];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			g[i][j]=g[i][j-1]+f[i][j];
		}
	}
	for(int i=m;i>=1;i--){
		for(int j=i;j<=m;j++){
			g[i][j]+=g[i+1][j];
		}
	}
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;
		cout<<g[l][r]<<'\n';
	}
	return 0;
}
