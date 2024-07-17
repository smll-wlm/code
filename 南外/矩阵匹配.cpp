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
#define ull unsigned long long
const int N=4e5+10;
using namespace std;
int n,m,k,cnt,mod;
int ans;
int a[N],b[N];
char c[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void debug(){
	for(int i=1;i<=m;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	for(int j=1;j<=m;j++){
		cout<<b[j]<<' ';
	}
}
signed main(){
	// qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%s",c);
		for(int j=0;j<m;j++){
			a[j+1]+=(c[j]=='.'?0:1<<i);
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%s",c);
		for(int j=0;j<m;j++){
			b[j+1]+=(c[j]=='.'?0:1<<i);
		}
	}
	sort(b+1,b+1+m);
	sort(a+1,a+1+m);
	// debug();
	for(int i=1;i<=m;i++){
		if(a[i]!=b[i]){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
/*
*/
