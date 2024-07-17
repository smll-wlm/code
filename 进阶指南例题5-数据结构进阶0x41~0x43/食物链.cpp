#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<unordered_map>
#define pii pair<int,int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=3e5+10;
using namespace std;
int n,m,len,ans;
int fa[N],d[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll fi_fa(int x){
	if(fa[x]==x)return x;
	return fa[x]=fi_fa(fa[x]);
}
in_vo merge(int x,int y){
	x=fi_fa(fa[x]);
	y=fi_fa(fa[y]);
	fa[x]=y;
}
void init(){
	for(int i=1;i<=3*n;i++){
		fa[i]=i;
	}
}
signed main(){
	qui();
	cin>>n>>m;
	init();
	while(m--){
		int op,x,y;
		cin>>op>>x>>y;
		if(x>n||y>n){
			ans++;
			continue;
		}
		if(op==1){
			if(fi_fa(x+n)==fi_fa(y)||fi_fa(x+2*n)==fi_fa(y)){
				ans++;
				continue;
			}
			merge(x,y);
			merge(x+n,y+n);
			merge(x+2*n,y+2*n);
		}
		else{
			if(x==y||fi_fa(x)==fi_fa(y)||fi_fa(x+2*n)==fi_fa(y)){
				ans++;
				continue;
			}
			merge(x, y + 2 * n);
			merge(x + n, y);
			merge(x + 2 * n, y + n);
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
