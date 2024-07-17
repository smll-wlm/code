#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#define int long long
const int N=1e5+10;
using namespace std;
int n,m,k;
int ans;
int c[N];
double f[N],t[N];
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		t[i]=floor((1.0+sqrt(5))/2.0*c[i]*c[i]);
	}
	for(int i=20000;i>=m;i--){
		for(int j=1;j<=n;j++){
			if(c[j]<i){
				f[i]+=1.0/n*t[j];
			}
			else{
				f[i]+=1.0/n*(f[i+c[j]]+1);
			}
		}
	}
	printf("%.3lf\n",f[m]);
	return 0;
}
/*

*/
