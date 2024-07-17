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
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=3e4+10;
using namespace std;
int n,m;
int si[N];
int fa[N],d[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll fi_fa(int x){
	if(fa[x]==x)return x;
	int r=fi_fa(fa[x]);
	d[x]+=d[fa[x]];
	return fa[x]=r;
}
in_vo merge(int x,int y){
	if(fi_fa(x)==fi_fa(y))return;
	x=fi_fa(x),y=fi_fa(y);
	fa[x]=y;
	d[x]=si[y];
	si[y]+=si[x];//顺带记录
}
void init(){
	for(int i=1;i<=N-1;i++){
		fa[i]=i;
		si[i]=1;
	}
}
signed main(){
	qui();
	init();
	int t;
	cin>>t;
	while(t--){
		char op;
		int x,y;
		cin>>op>>x>>y;
		// cout<<op<<endl;
		if(op=='M'){
			merge(x,y);
		}
		else{
			if (fi_fa(x)==fi_fa(y)){
				cout<<max(abs(d[x]-d[y])-1,0);
			}
			else{
				cout<< -1;
			}
			cout<<"\n";
		}
	}
	return 0;
}
/*
*/
