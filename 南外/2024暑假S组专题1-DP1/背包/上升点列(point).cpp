#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include <cassert>
#define pii pair<int,int>
#define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=1e3+10;
using namespace std;
int n,m;
int ans;
struct node{
	int x, y;
}a[N];
int f[N][N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+1+n,[](node aa,node bb){return aa.x==bb.x?aa.y<bb.y:aa.x<bb.x;});
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			f[i][j]=1+j;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(a[j].y>a[i].y)continue;
			int dis=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)-1;
			// assert(dis>=0);
			for(int k=dis;k<=m;k++){
				f[i][k]=max(f[i][k],f[j][k-dis]+dis+1);
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i][m]);
	}
	cout<<ans;
	return 0;
}
/*
*/
