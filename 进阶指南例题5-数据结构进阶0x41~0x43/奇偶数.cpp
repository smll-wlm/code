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
// #define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=3e4+10;
using namespace std;
int n,m,len,ans;
int fa[N],d[N];
unordered_map<int,int> ma;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll getf(int x){
	if(ma.count(x)==0){
		ma[x]=++len;
	}
	return ma[x];
}
in_ll fi_fa(int x){
	if(fa[x]==x)return x;
	int r=fi_fa(fa[x]);
	d[x]^=d[fa[x]];
	return fa[x]=r;
}
void init(){
	for(int i=1;i<=N-1;i++){
		fa[i]=i;
	}
}
signed main(){
	qui();
	init();
	cin>>n;
	int t;
	cin>>t;
	m=t;
	ans=t;
	while(t--){
		int x,y;string s; 
		cin>>x>>y>>s;
		int a=getf(x-1),b=getf(y);
		int fa1=fi_fa(a),fb=fi_fa(b);
		int tot=0;
		if(s=="odd"){
			tot=1;
		}
		if(fa1==fb){
			if((d[a]^d[b])!=tot){
				ans=m-t-1;
				break;
			}
		}
		else{
			fa[fa1]=fb;
			d[fa1]=d[a]^d[b]^tot;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
/*
*/
