#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<bitset>
#define pii pair<int,int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=1e5+10;
using namespace std;
int n,m;
bitset<100010> f;
// bool f[100010];
int ans;
struct node{
	int val,num;
}a[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	f[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].num;j++)
			f|=f<<a[i].val;
	}
	for(int i=1;i<=m;i++)ans+=f[i];
	cout<<ans;
	return 0;
}
/*
*/
