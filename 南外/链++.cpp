#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#define int long long
#define in_vo inline void
#define in_ll inline long long
using namespace std;
const int N=2e3+10;
int n,m;
int vis[N],d[N],anss[N],ma[N][N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			ma[i][j]=ma[j][i]=j-i;
		}
	}
	int x,y;
	cin>>x>>y;
	ma[x][y]=ma[y][x]=1;
	for(int i=1;i<=n;i++){
		int len;
		for(int j=i+1;j<=n;j++){
			if((i<=x&&j<=x)||(i>=y&&j>=y))len=ma[i][j];
			if(i<=x&&j>x&&j<y){
				len=ma[i][x]+min(ma[j][y]+ma[x][y],ma[j][x]);
			}
			if(i<=x&&j>=y){
				len=ma[i][x]+ma[j][y]+ma[x][y];
			}
			if((i>x&&i<y)&&(j>x&&j<y)){
				len=min(ma[i][j],ma[i][x]+ma[j][y]+ma[x][y]);
			}
			if(i>x&&i<y&&j>=y){
				len=ma[j][y]+min(ma[i][x]+ma[x][y],ma[i][y]);
			}
			anss[len]++;
		}
	}
	for(int i=1;i<n;i++){
		cout<<anss[i]<<endl;
	}
	return 0;
}
