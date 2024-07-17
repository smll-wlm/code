#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#define int long long
const int N=1e5+10;
using namespace std;
int n,q,k,ans;
vector<int> v[N];
int vis[N],d[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void dfs(int step,int pre){
	for(auto it:v[step]){
		if(vis[it]||it==pre)continue;
		d[it]=d[step]+1;
		vis[it]=1;
		dfs(it,step);
	}
}
signed main(){
	qui();
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	d[1]=0;
	// for(int i=1;i<=n;i++)cout<<d[i]<<' ';
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=(d[x]+d[y])&1;
		if(ans){
			cout<<"Road\n";
		}
		else{
			cout<<"Town\n";
		}
	}
	return 0;
}
/*

*/
