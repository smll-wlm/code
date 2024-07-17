#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=1e6+10;
using namespace std;
int n,m,k,cnt,mod;
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	int d=exgcd(b,a%b,x,y);
	int z=x;
	x=y;y=z-y*(a/b);
	return d;
}
in_ll Mod(int a,int b){
	return ((a%b)+b)%b;
}
signed main(){
	qui();
	cin>>n;
	int a1,m1;
	cin>>a1>>m1;
	for(int i=1;i<n;i++){
		int a2,m2,k1,k2;
		cin>>a2>>m2;
		int d=exgcd(a1,-a2,k1,k2);
		if((m2-m1)%d){
			cout<<"-1"<<endl;
			return 0;
		}
		k1=Mod(k1*(m2-m1)/d,abs(a2/d));
		m1=k1*a1+m1;
		a1=abs(a1/d*a2);
	}
	cout<<m1<<endl;
	return 0;
}
/*
*/
