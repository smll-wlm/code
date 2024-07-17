#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<bitset>
#define pii pair<int,int>
#define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=1e3+10;
using namespace std;
int n,m;
int ans,fl;
int a[N],w[N],v[N],num[N],cnt;
int tot;
int maxx;
bitset<10010> f;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo init(){
	memset(a,0,sizeof(a));
	f.reset();fl=0;
	f[0]=1;
}
in_vo solve(){
	for(int i=1;i<=n-1;i++){
		f|=f<<a[i];
	}
	for(int i=1;i<=m-5;i++){
		if(f[i]==1)fl=i;
	}
	fl+=maxx;
	cout<<m-fl;
}
signed main(){
	qui();
	while(1){
		cin>>n;
		if(!n)return 0;
		init();
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			a[i]=x;
		}
		sort(a+1,a+1+n);
		maxx=a[n];
		cin>>m;
		solve();
		cout<<'\n';
	}
	return 0;
}
/*
*/
