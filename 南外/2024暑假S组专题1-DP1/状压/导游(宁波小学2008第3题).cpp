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
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=1e2+10;
using namespace std;
int n,m;
int ans;
// struct node{
// 	int v,w,num;
// }a[N];
int s[N];
int vis[N];
int a[N][N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo dfs(int step,int num){
	if(step==n+1){
		ans=max(ans,num);
		return;
	}
	int res=0;
	res=s[n]-s[step-1];
	if(num+res<=ans)return;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(step+1,num+a[step][i]);
			vis[i]=0;
		}
	}
}
signed main(){
	qui();
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			s[i]=max(s[i],a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		s[i]+=s[i-1];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
/*
*/
