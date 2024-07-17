#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define int long long
const int N=1e6+10;
const int mod=998244353;
using namespace std;
int n,m,k,ans=1,c,d;
int vis[N];
vector<int> v[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void dfs(int step){
	vis[step]=1;
	c++;d+=v[step].size();
	for(auto it:v[step]){
		if(!vis[it]){
			dfs(it);
		}
	}
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			c=d=0;
			dfs(i);
			if(c==d/2){
				ans=ans*2%mod;
			}
			else{
				cout<<0;
				return 0;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*

*/
