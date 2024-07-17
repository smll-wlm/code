#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
#include<unordered_map>
#include <map>
#define pii pair<int, int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
const int N = 1e5+10;
using namespace std;
int ans[N];
int l1[N],r1[N];
int n,m;
int pos,maxx;
struct shoe{
	int num,s,d;
}a[N];
struct water{
	int pos,dep;
}h[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo add(int x){
	int l=x,r=x;
	l1[x]=r1[x]=x;
	if(l1[x-1]){
		l=l1[x-1];
		l1[r1[x]]=l1[x-1];
		r1[l1[x-1]]=r1[x];
		l1[x-1]=0;
	}
	if(r1[x+1]){
		r=r1[x+1];
		r1[l1[x]]=r1[x+1];
		l1[r1[x+1]]=l1[x];
		r1[x+1]=0;
	}
	maxx=max(maxx,r-l+1);
}
signed main()
{
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>h[i].dep;
		h[i].pos=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].s>>a[i].d;
		a[i].num=i;
	}
	pos=1;
	sort(h+1,h+1+n,[](water x,water y){return x.dep>y.dep;});
	sort(a+1,a+1+m,[](shoe x,shoe y){return x.s==y.s?x.d>y.d:x.s>y.s;});
	for(int i=1;i<=m;i++){
		while(pos<=n&&h[pos].dep>a[i].s){
			add(h[pos].pos);
			pos++;
		}
		if(a[i].d>maxx){
			ans[a[i].num]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
