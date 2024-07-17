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
const int N=1e2+10;
using namespace std;
int n,m;
int k;
int f[N][N][N];
int a[N],b[N],c[N];
string s1,s2,s3;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>s1>>s2>>s3;
	n=s1.size();
	m=s2.size();
	k=s3.size();
	for(int i=1;i<=N;i++){
		f[i][0][0]=0;
		f[0][i][0]=0;
		f[0][0][i]=0;
	}
	for(int i=1;i<=n;i++){
		a[i]=s1[i-1]-'a'+1;
	}
	for(int i=1;i<=m;i++){
		b[i]=s2[i-1]-'a'+1;
	}
	for(int i=1;i<=k;i++){
		c[i]=s3[i-1]-'a'+1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int l=1;l<=k;l++){
				f[i][j][l]=max(max(f[i-1][j][l],f[i][j-1][l]),f[i][j][l-1]);
				if(a[i]==b[j]&&b[j]==c[l]){
					f[i][j][l]=max(f[i][j][l],f[i-1][j-1][l-1]+1);
				}
			}
		}
	}
	cout<<f[n][m][k];
	return 0;
}
/*
*/
