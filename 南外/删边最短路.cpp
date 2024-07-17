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
const int N=410;
using namespace std;
int n,m;
int s[N*N],t[N*N],fa[N*N],vis[N][N],d[N*N];
vector<pii> v[N*N];
queue <int> q;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void bfs(int x){
	while(!q.empty())q.pop();
	q.push(1);
	for(int i=1;i<=n;i++){
		d[i]=0;
	}
	d[1]=1;
	while(q.size()){
		int t1=q.front();
		q.pop();
		for(auto it:v[t1]){
			if(!d[it.fir]&&it.sec!=x){
				d[it.fir]=d[t1]+1;
				fa[it.fir]=t1;
				q.push(it.fir);
			}
		}
	}
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		s[i]=x;t[i]=y;
		v[s[i]].push_back({t[i],i});
	}
	bfs(0);
	d[0]=d[n];
	for(int i=n;i;i=fa[i]){
		vis[fa[i]][i]=1;
	}
	for(int i=1;i<=m;i++){
		if(!vis[s[i]][t[i]])cout<<d[0]-1<<endl;
		else{
			bfs(i);
			cout<<d[n]-1<<endl;
		}
	}
	return 0;
}
/*
*/
