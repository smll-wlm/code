#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
#define pii pair<int, int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
const int N = 1e5+10;
using namespace std;
int n,m;
int ans;
struct node{
	int w,h,s;
}a[N];
int f[1<<21],g[1<<21];
int ma[21][21];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main()
{
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].h>>a[i].w>>a[i].s;
	}
	sort(a+1,a+1+n,[](node x,node y){return x.s==y.s?x.w<y.w:x.s>y.s;});
	ans=-1e18;
	f[0]=1e9+10;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(((i>>j)&1)==1)continue;
			if(f[i]>=a[j+1].w){
				g[i+(1<<j)]=g[i]+a[j+1].h;
				f[i+(1<<j)]=max(f[i+(1<<j)],min(f[i]-a[j+1].w,a[j+1].s));
			}
		}
	}
	for(int i=1;i<(1<<n);i++){
		if(g[i]>=m){
			ans=max(ans,f[i]);
		}
	}
	if(ans<0){
		cout<<"Mark is too tall";
	}
	else{
		cout<<ans;
	}
	return 0;
}
