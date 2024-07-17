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
#define in_vo inline void
#define in_ll inline long long
const int N=1e3+10;
using namespace std;
int n,m;
int co;
int w[N],v[N];
int ma[N][N];
int f[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo init(){
	memset(w,0,sizeof(w));
	memset(v,0,sizeof(v));
	for(int i=1;i<=N;i++){
		f[i]=1e9;
	}
	f[0]=0;
}
signed main(){
	qui();
	cin>>m>>n>>co;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ma[i][j];
		}
	}
	memset(f,-0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--)P{
			for(int k=1;k<=___;k++){
				if(j>=___){
					f[j]=max(f[j],f[j-__]+__);
				}
			}
		}	
	}
	cout<<f[m];
	return 0;
}
/*
*/
