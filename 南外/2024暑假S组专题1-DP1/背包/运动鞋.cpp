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
const int N=1e5+10;
using namespace std;
int n,m;
int k,res;
struct node{
	int p,v,w;
}a[N];
int aa[N];
int mv[110][110],mw[110][110];
int sl[N],sl1[N],f[110][N];//f[i][j]表示第i组时候花j块钱的最大价值
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void init(){
	memset(f,-1,sizeof(f));
	for(int i=0;i<=m;i++){
		f[0][i]=0;
	}
}
void cheat(){
	for(int i=1;i<=n;i++){
		aa[a[i].p]=min(aa[a[i].p],a[i].v);
	}
	for(int i=1;i<=k;i++){
		res+=aa[i];
	}
	if(res>m){
		cout<<"Impossible";
		exit(0);
	}
}
signed main(){
	qui();
	cin>>n>>m>>k;
	memset(aa,0x3f3f3f,sizeof(aa));
	for(int i=1;i<=n;i++){
		cin>>a[i].p>>a[i].v>>a[i].w;
		sl[a[i].p]++;
		
//		mv[a[i].p][sl[a[i].p]]=a[i].v;
//		mw[a[i].p][sl[a[i].p]]=a[i].w;
	}
	for(int i=1;i<=k;i++){
		sl1[i]=sl1[i-1]+sl[i-1];
	}
	sort(a+1,a+1+n,[](node a,node b){return a.p==b.p?a.v<b.v:a.p<b.p;});
	//cheat pts
	cheat();
	//init
	init();
	//dp
	for(int i=1;i<=k;i++){
		for(int j=1;j<=sl[i];j++){
			int vn=a[sl1[i]+j].v,wn=a[sl1[i]+j].w;
			for(int l=m-vn;l>=0;l--){
				if(f[i][l]!=-1){
					f[i][l+vn]=max(f[i][l+vn],f[i][l]+wn);
				}
				if(f[i-1][l]!=-1){
					f[i][l+vn]=max(f[i-1][l]+wn,f[i][l+vn]);
				}
			}
		}
	}
	
	// for(int i=1;i<=k;i++){
	// 	for(int j=1;j<=sl[i];j++){
	// 		int vn=mv[i][j],wn=mw[i][j];
	// 		for(int l=m-vn;l>=0;l--){
	// 			if(f[i][l]!=-1){
	// 				f[i][l+vn]=max(f[i][l+vn],f[i][l]+wn);
	// 			}
	// 			if(f[i-1][l]!=-1){
	// 				f[i][l+vn]=max(f[i-1][l]+wn,f[i][l+vn]);
	// 			}
	// 		}
	// 	}
	// }
	cout<<f[k][m];
	return 0;
}
/*
*/
