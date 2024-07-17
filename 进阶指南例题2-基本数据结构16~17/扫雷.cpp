#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define int long long
const int N=1e6+10;
const int mod=1e9+7;
using namespace std;
int n,m,k,c,d;
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
int calc(int a,int b){
	int cnt=1;
	while(b!=0){
		if(b&1){
			cnt=cnt*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return cnt;
}
signed main(){
	qui();
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		ans=(1+ans)*y%mod*calc(x,mod-2)%mod;
	}
	cout<<ans;
	return 0;
}
/*

*/
