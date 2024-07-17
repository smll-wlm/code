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
int n,m,q;
double ans,p;
int t1,t2,zs;
double f[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	scanf("%lld %lf",&n,&p);
	f[n]=0.0;
	for(int i=n-1;i>=1;i--){
		double p1=1.0/(i*(n-i)*p/n/(n-1)*2);
		f[i]=p1+f[i+1];
	}
	printf("%.3lf",f[1]);
	return 0;
}
/*
*/
