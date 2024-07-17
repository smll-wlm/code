#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>
#define int long long
#define in_vo inline void
#define in_ll inline long long
#define fir first
#define sec second
const int N=3e5+10;
using namespace std;
int n,m,k,cnt,mod;
int ans;
int fa[N],c[N];
map<int,int> ma[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll fi_fa(int x){
	if(x==fa[x])return x;
	return fa[x]=fi_fa(fa[x]);
}
in_vo add(int x,int y){
	int fx=fi_fa(x),fy=fi_fa(y);
	if(fx==fy)return;
	if(ma[fx].size()<ma[fy].size()){
		swap(fx,fy);
	}
	for(auto it:ma[fy]){
		ma[fx][it.fir]+=it.sec;
	}
	fa[fy]=fx;
	ma[fy].clear();
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		ma[i][c[i]]=1;
		fa[i]=i;
	}
	while(m--){
		int f,x,y;
		cin>>f>>x>>y;
		if(f==1){
			add(x,y);
		}
		else{
			cout<<ma[fi_fa(x)][y]<<endl;
		}
	}
	return 0;
}
/*
*/
