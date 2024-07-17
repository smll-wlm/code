#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define pii pair<int,int>
#define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=3e3+10;
using namespace std;
int n,m;
int f[N][N];
int a[N],b[N];
string s1,s2;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>s1>>s2;
	n=s1.size();
	m=s2.size();
	for(int i=1;i<=n;i++){
		a[i]=s1[i-1]-'a'+1;
	}
	for(int i=1;i<=m;i++){
		b[i]=s2[i-1]-'a'+1;
	}
	// memset(f,)
	for(int i=1;i<=n;i++){
		f[i][0]=0;
		f[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if(a[i]==b[j]){
				f[i][j]=max(f[i][j],f[i-1][j-1]+1);
			}
		}
	}
	cout<<f[n][m];
	return 0;
}
/*
*/
