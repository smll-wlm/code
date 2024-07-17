#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#include<string>
#define int long long
const int N=1e5+10;
using namespace std;
int n,q,k;
int ans;
int he[N],ne[N],to[N],w[N],tot;
int vis[N],d[N][50],a[N];
priority_queue<pair<int,int> > q1;
vector<int> v[N];
void dfs(int step,int pre){
	d[step][1]=a[step];
	for(auto it:v[step]){
		if(it==pre)continue;
		dfs(it,step);
		for(int i=1;i<=20;i++){
			d[step][i+20]=d[it][i];
		}
		sort(d[step]+1,d[step]+1+20*2,greater<int>());
	}
}
signed main(){
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",d[x][y]);
	}
	return 0;
}
/*

*/
