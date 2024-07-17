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
const int N=1e6+10;
using namespace std;
int n,m;
int a[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void init(){
	a[0]=1;
	for(int i=1;i<=N;i++){
		int z=i;
		int maxx=0,minn=9;
		while(z){
			maxx=max(maxx,z%10);
			if(z%10!=0){
				minn=min(minn,z%10);
			}
			z/=10;
		}
		a[i]=(!a[i-minn]||!a[i-maxx]);
	}
}
signed main(){
	qui();
	init();
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		if(a[x]==1){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}
/*
*/
