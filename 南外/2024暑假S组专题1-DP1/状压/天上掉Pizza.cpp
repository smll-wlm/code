#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<bitset>
#include <iomanip>
#define pii pair<int,int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
const int N=1e2+10;
using namespace std;
int n,m;
double ans;
int s[1<<16];
int ma[N][N];//ma[i][j]表示先i后j有对应的折扣
double f[1<<16];
struct node{
	int s,mon;
}a[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo init(){
	mem(ma,0);
	for(int i=1;i<=1<<16;i++){
		f[i]=1e9;
		s[i]=0;
	}
	ans=1e9+10;
}
signed main(){
	qui();
	while(1){
		cin>>n;
		if(!n)return 0;
		init();
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[i].s=y;a[i].mon=x;
			for(int j=1;j<=z;j++){
				int xx,yy;
				cin>>xx>>yy;
				ma[i][xx]=yy;
			}
		}
		m=1<<n;
		for(int i=0;i<m;i++){
			for(int j=1;j<=n;j++){
				if(((i>>(j-1))&1)==0){
					double z=1;
					for(int k=1;k<=n;k++){
						if(((i>>(k-1))&1)==1)
							z=z*(1-ma[k][j]*0.01);
					}
					s[i+(1<<(j-1))]=s[i]+a[j].s;
					f[i+(1<<(j-1))]=min(f[i+(1<<(j-1))],f[i]+z*a[j].mon);
				}
			}
		}
		for(int i=1;i<m;i++){
			ans=min(ans,f[i]/(double)s[i]);
		}
		cout<<fixed<<setprecision(4)<<ans<<'\n';
	}
	return 0;
}
/*
*/
