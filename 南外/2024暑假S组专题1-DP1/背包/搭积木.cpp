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
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=1e5+10;
using namespace std;
int n,m;
int f[1010][1010];
struct node{
	int val,ti;
}a[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i].ti>>a[i].val;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(j>=a[i].ti){
				f[i][j]=max(f[i-1][j],f[i-1][j-a[i].ti]+a[i].val);
			}
			else{
				f[i][j]=f[i-1][j];
			}
		}
	}
	cout<<f[m][n];
	return 0;
}
/*
*/
