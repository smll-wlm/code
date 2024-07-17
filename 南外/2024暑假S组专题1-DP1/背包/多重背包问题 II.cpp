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
const int N=2e4+10;
using namespace std;
int n,m;
int v,w,s,tot;
int f[N];
struct node{
	int v,val;
}a[N];
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v>>w>>s;
		int t=1;
		while(s){
			if(t>s)t=s;
			s-=t;
			a[++tot].v=t*v;
			a[tot].val=t*w;
			t<<=1;
		}
	}
	for(int i=1;i<=tot;i++){
		for(int j=m;j>=a[i].v;j--){
			f[j]=max(f[j],f[j-a[i].v]+a[i].val);
		}
	}
	cout<<f[m];
	return 0;
}
/*
*/
