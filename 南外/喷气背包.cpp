#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define pii pair<int,int>
// #define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=1e5+10;
using namespace std;
int n,m;
int ans;
int ma[15][N],ans1[N];
int vis[15][N],s[N],t[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo dfs(int x,int y,int cx){
	if(y>n){
		cout<<ans<<endl;
		for(int i=1;i<=ans;i++){
			cout<<s[i]<<' '<<t[i]<<endl;
		}
		exit(0);
	}
	if(ma[x][y]==1||vis[x][y]){
		return;
	}
	vis[x][y]=1;ans1[y]=x;
	dfs(min(x+1,10),y+1,0);
	if(cx){
		t[ans]++;
	}
	else{
		s[++ans]=y-1;
		t[ans]=1;
	}
	dfs(max(x-1,1),y+1,1);
	if(cx){
		t[ans]--;
	}
	else{
		t[ans--]=0;
	}
}
signed main(){
	qui();
	cin>>n;
	for(int i=1;i<=10;i++){
		string s;
		cin>>s;
		for(int j=1;j<=n;j++){
			ma[i][j]=(s[j-1]=='.')?0:1;
		}
	}
	dfs(10,1,0);
	return 0;
}
/*
*/
