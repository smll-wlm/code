#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include<string>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
#define pii pair<int, int>
#define y1 y114514
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=257;
int n,m;
int ff;
struct node{
	int r,g,b;
}a[200010];
int s[N][N][N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll calc(int x,int y,int z,int l){
	int res=s[x][y][z];
	res-=s[x-l][y][z]+s[x][y-l][z]+s[x][y][z-l];
	res+=s[x-l][y-l][z]+s[x][y-l][z-l]+s[x-l][y][z-l];
	res-=s[x-l][y-l][z-l];
	return res;
}
in_ll chk(int x){
	for(int i=x;i<=ff;i++){
		for(int j=x;j<=ff;j++){
			for(int k=x;k<=ff;k++){
				if(calc(i,j,k,x)>=m){
					return 1;
				}
			}
		}
	}
	return 0;
}
signed main()
{
	freopen("rgb.in","r",stdin);
	freopen("rgb.out","w",stdout);
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		x++;y++;z++;
		ff=max(ff,max(x,max(y,z)));
		a[i].r=x;a[i].g=y;a[i].b=z;
		s[x][y][z]++;
	}
	for(int i=1;i<=ff;i++){
		for(int j=1;j<=ff;j++){
			for(int k=1;k<=ff;k++){
				s[i][j][k]+=s[i][j][k-1];
			}
		}
	}
	for(int i=1;i<=ff;i++){
		for(int j=1;j<=ff;j++){
			for(int k=1;k<=ff;k++){
				s[i][j][k]+=s[i][j-1][k];
			}
		}
	}
	for(int i=1;i<=ff;i++){
		for(int j=1;j<=ff;j++){
			for(int k=1;k<=ff;k++){
				s[i][j][k]+=s[i-1][j][k];
			}
		}
	}
	int l=1,r=ff+1;
	while(l<=r){
		int mid=l+r>>1;
		if(chk(mid)){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<l-1;
	return 0;
}
