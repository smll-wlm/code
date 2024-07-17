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
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=2e3+10;
const int inf=1e8+10;
using namespace std;
int n,m;
int d[N],vis[N];
int ans[N];
vector<pii> v[N];
priority_queue<pii> q;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo init(){
	// memset(ma,0x3f,sizeof(ma));
	for(int i=0;i<=n+1;i++){
		d[i]=inf;
		vis[i]=0;
	}
}
in_vo dij(int st){
	init();
	q.push({0,st});
	while(!q.empty()){
		int t=q.top().sec;
		q.pop();
		if(vis[t])continue;
		int d1=d[t];
		if(t==st)d1=0;
		for(auto it:v[t]){
			if(d[it.fir]>d1+it.sec){
				d[it.fir]=d1+it.sec;
				q.push({-d[it.fir],it.fir});
			}
		}
	}
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back({y,z});
	}
	for(int i=1;i<=n;i++){
		dij(i);
		if(d[i]==inf)cout<<"-1"<<endl;
		else cout<<d[i]<<endl;
	}
	return 0;
}
/*
*/
