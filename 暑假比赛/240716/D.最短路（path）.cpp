#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include<string>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
#define pii pair<int, int>
#define y1 y114514
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=2e5+10;
int n,m;
struct node{
	int v,w;
};
int vis[N];
vector<node> v[N];
int from[N];
int d[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo dij(){
	priority_queue<pii> q;
	q.push({0,1});
	for(int i=1;i<=n;i++){
		d[i]=1e9+10;
	}
	d[1]=0;
	while(!q.empty()){
		pii x=q.top();
		q.pop();
		int now=x.sec;
		if(vis[now]==1)continue;
		vis[now]=1;
		for(auto [to,w]:v[now]){
			if(d[to]>d[now]+w){
				d[to]=d[now]+w;
				from[to]=now;
				q.push({-d[to],to});
			}
		}
	}
}
signed main()
{
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	qui();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	dij();
	for(int i=2;i<=n;i++){
		int ans=1e9+10;
		if(v[i].size()==1){
			cout<<"-1"<<'\n';
			continue;
		}
		for(auto [to,w]:v[i]){
			if(to!=from[i])
				ans=min(ans,d[to]+w);
		}
		if(ans==1e9+10)ans=-1;
		cout<<ans<<'\n';
	}
	return 0;
}
