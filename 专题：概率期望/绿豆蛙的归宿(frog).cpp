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
const int N=2e5+10;
const int mod=1e9+9;
using namespace std;
int n,m;
int he[N],tot,ed[N],to[N],ne[N];
int rd[N],cd[N];
double d[N];
queue<int> q;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo add(int x,int y,int z){
	to[++tot]=y;
	ed[tot]=z;
	ne[tot]=he[x];
	he[x]=tot;
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(y,x,z);
		rd[x]++,cd[x]++;
	}
	q.push(n);
	while(q.size()){
		int t=q.front();
		q.pop();
		for(int i=he[t];i;i=ne[i]){
			int y=to[i];
			d[y]+=(d[t]+ed[i])/rd[y];
			cd[y]--;
			if(cd[y]==0)q.push(y);
		}
	}
	printf("%.2lf",d[1]);
	return 0;
}
/*
*/
