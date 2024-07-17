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
int ans;
string s;
int ma[N][N];
int a[N],sum[1<<10],f[1<<10][1<<10][3];//
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			a[i]<<=1;
			if(s[j]=='H')a[i]++;
		}
	}   
	for(int i=0;i<(1<<m);i++){
		int tot=0,x=i;
		while(x){
			if(x&1)tot++;
			x>>=1;
		}
		sum[i]=tot;
	}
	for(int i=0;i<(1<<m);i++){
		if(!(i&a[0]||(i&(i<<1))||(i&(i<<2)))){
			f[0][i][0]=sum[i];
		}
	}
	for(int i=0;i<(1<<m);i++){
		for(int j=0;j<(1<<m);j++){
			if(!(i&j||i&a[0]||j&a[1]||(i&(i<<1))||(i&(i<<2))||(j&(j<<1))||(j&(j<<2))))
				f[i][j][1]=sum[i]+sum[j];
		}
	}
	for(int i=2;i<n;i++){
		for(int j=0;j<(1<<m);j++){
			if(j&a[i-1]||(j&(j<<1))||(j&(j<<2)))continue;
			for(int k=0;k<(1<<m);k++){
				if(k&a[i]||j&k||(k&(k<<1))||(k&(k<<2)))continue;
				for(int l=0;l<(1<<m);l++){
					if(l&j||l&k||l&a[i-2]||l&(l<<1)||(l&(l<<2)))continue;
					
					f[j][k][i%3]=max(f[j][k][i%3],f[l][j][(i-1)%3]+sum[k]);
				}
			}
		}
	}
	for(int i=0;i<(1<<m);i++){
		for(int j=0;j<(1<<m);j++){
			ans=max(ans,f[i][j][(n-1)%3]);
		}
	}
	cout<<ans;
	return 0;
}
