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
const int INF=45000;
using namespace std;
int n,q,k,ans;
int a[N],vis[N];
vector<int> v[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
bool dfs(int step,int pre){
	for(auto it:v[step]){
		if(it==pre)return 1;
	}
	return 0;
}
signed main(){
	qui();
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1,j=2;j<=n;i++){
		if(i==j){
			cout<<"No";
			return 0;
		}
		while(dfs(a[i],a[j]))++j;
	}
	cout<<"Yes";
	return 0;
}
/*

*/
