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
const int mod=1e18;
using namespace std;
int n,m,k,cnt;
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
inline int ex_gcd(int a,int b,int &x,int &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	int d=ex_gcd(b,a%b,x,y);
	int z=x;
	x=y;
	y=z-y*(a/b);
	return d;
}
signed main(){
	qui();
	cin>>n>>m;
	int x=0,y=0;
	ex_gcd(n,m,x,y);
	cout<<(x%m+m)%m;
	return 0;
}
/*
*/
