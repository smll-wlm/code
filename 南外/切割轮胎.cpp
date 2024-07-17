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
const int N=1e5+10;
using namespace std;
int n,m;
int a[N];
int phi[N],t[N];
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void phii(){
	for(int i=2;i<=N;i++){
		phi[i]=i;
	}
	for(int i=2;i<=N;i++){
		if(phi[i]==i){
			for(int j=i;j<=N;j+=i){
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}
signed main(){
	qui();
	cin>>n;
	for(int i=1;i<=n+1;i++){
		int x;
		cin>>x;
		++t[x];
	}
	phii();
	for(int i=2;i<=N;i++){
		for(int j=i;j<=N;j+=i){
			if(t[j]){
				ans+=phi[i];
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
