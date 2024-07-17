#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<bitset>
#define pii pair<int,int>
#define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=1e4+10;
using namespace std;
int n,m;
int f[N][2];
int v[N];
int a[N];
vector<int> son[N];
int ans,root;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo dp(int x){
	f[x][0]=0;
	f[x][1]=a[x];
	for(auto it:son[x]){
		dp(it);
		f[x][0]+=max(f[it][0],f[it][1]);
		f[x][1]+=f[it][0];
	}
}
signed main(){
	qui();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x]=1;
		son[y].push_back(x);
	}
	int x1,x2;
	cin>>x1>>x2;
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			root=i;
			break;
		}
	}
	// cout<<v[5]<<endl;
	dp(root);
	cout<<max(f[root][0],f[root][1])<<endl;
	return 0;
}
/*
*/
