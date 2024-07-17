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
const int N=5e5+10+10;
const int mod=1e9+9;
using namespace std;
int n,m,p,q;
double ans;
int t1,t2,zs;
double f[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n;
	f[n]=1.0;
	ans+=f[n];
	for(int i=n-1;i>=1;i--){
		f[i]=(ans+n-i+1)/(n-i);
		ans+=f[i];
	}
	printf("%.2lf",f[1]-1);
	return 0;
}
/*
*/
