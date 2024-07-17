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
const int N=3e3+10;
using namespace std;
int n,m;
int f[N][N];
int a[N],b[N],c[N];
int ans;
vector<int> v;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-(b+1);
	for(int i=1;i<=n;i++){
		int tmp=lower_bound(b+1,b+1+m,a[i])-b;
		c[tmp]=a[i];
	}
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		int val=f[i-1][0];
		for(int j=1;j<=m;j++){
			val=min(f[i-1][j],val);
			f[i][j]=val+abs(c[j]-a[i]);
		}
	}
	ans=1e9;
	for(int i=1;i<=n;i++){
		ans=min(ans,f[n][i]);
	}
	cout<<ans;
	return 0;
}
/*
*/
