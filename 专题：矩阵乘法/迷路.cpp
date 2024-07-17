#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
#include<set>
#include<vector>
#include<cmath>
#define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=1010;
const int mod=2009;
using namespace std;
int n,m,k,cnt,s,t;
int a[N][N],f[N][N];
int ans;
int c[N][N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo mul(){
	memset(c,0,sizeof(c));
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				c[i][j]=(c[i][j]+f[i][k]*a[k][j])%mod;
			}
		}
	}
	memcpy(f,c,sizeof(c));
}
in_vo mul_self(){
	memset(c,0,sizeof(c));
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				c[i][j]=(c[i][j]+a[i][k]*a[k][j])%mod;
			}
		}
	}
	memcpy(a,c,sizeof(c));
}
signed main(){
	qui();
	cin>>n>>m;
	n*=9;
	char c1;
	for(int i=0;i<n;i++){
		if(i%9==0){
			for(int j=0;j<n;j+=9){
				cin>>c1;
				if(c1=='0')continue;
				a[i][j+c1-'1']=1;
			}
		}
		else{
			a[i][i-1]=1;
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<a[i][j]<<' ';
	// 	}
	// 	cout<<endl;
	// }
	memcpy(f,a,sizeof(a));
	m--;
	while(m){
		if(m&1)
		{
			mul();
		}
		mul_self();
		m>>=1;
	}
	
	cout<<f[0][n-9];
	return 0;
}
/*
*/
