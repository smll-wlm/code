#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<cstring>
#include<vector>
#include<string>
#define int long long
const int N=1e4+10;
using namespace std;
int n,m;
int ans;
vector<int> v[N];
int vis[N];
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void dfs(int step){
	if(vis[step])return;
	ans++;
	vis[step]=1;
	for(auto it:v[step]){
		dfs(it);
	}
}
signed main(){
	quickcin();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dfs(i);
	}
	cout<<ans;
	return 0;
}
/*

*/
