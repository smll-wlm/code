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
int w[N],v[N];
int w1,w2;
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
	int T;
	cin>>T;
	while(T--){
		init();
		cin>>w1>>w2;
		m=w2-w1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>w[i]>>v[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=v[i];j<=m;j++){
				f[j]=min(f[j],f[j-v[i]]+w[i]);
			}
		}
		if(f[m]==1e9){
			cout<<"This is impossible.";
		}
		else{
			cout<<"The minimum amount of money in the piggy-bank is "
			<<f[m]<<'.';
		}
		cout<<'\n';
	}
	return 0;
}
/*
*/
