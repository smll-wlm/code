#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<iomanip>
#define pii pair<int,int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=1e3+10;
using namespace std;
int n,m;
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo dfs(int pre,int num){
	if(num>=n&&num<=m){
		ans++;
		// return;
	}
	if(10*num+1>m)return;
	for(int i=pre;i<=9;i++){
		dfs(i,num*10+i);
	}
}
signed main(){
	qui();
	while(cin>>n>>m){
		ans=0;
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
*/
