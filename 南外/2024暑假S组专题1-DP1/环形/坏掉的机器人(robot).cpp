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
int x,y;
double f[N][N];//表示从(n,m)到达(i,j)的期望步数
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	cin>>x>>y;
	if(n==x){
		return cout<<"0.0000",0;
	}
	for(int i=n-1;i>=x;i--){//因此f[n][j]都是0恒定
		for(int t=1;t<=100;t++){
			for(int j=1;j<=m;j++){
				if (m==1){
					f[i][1]=(f[i][1]+f[i+1][1])/2+1;
					continue;
				}
				if(j==1){
					f[i][j]=(f[i][1]+f[i][2]+f[i+1][1])/3+1;
				}
				else if(j==m){
					f[i][j]=(f[i][m]+f[i][m-1]+f[i+1][m])/3+1;
				}
				else{
					f[i][j]=(f[i][j]+f[i][j-1]+f[i][j+1]+f[i+1][j])/4+1;
				}
			}
		}
	}
	cout<<fixed<<setprecision(4)<<f[x][y];
	return 0;
}
/*
*/
