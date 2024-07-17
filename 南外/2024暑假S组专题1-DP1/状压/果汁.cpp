#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<iomanip>
#define pii pair<int,int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
const int N=1e2+15;
using namespace std;
int n,m;
int ans;
int a[N],p[N];
int f[1<<16];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll dfs(int x){
	if(f[x]!=-1){
		return f[x];
	}
	int cnt=0,num=0;
	for(int i=0;i<n;i++){
		if(x&(1<<i)){
			cnt++;
			num+=a[i];
		}
	}
	f[x]=(num/m)*p[m];
	if(num%m==0){
		f[x]+=(cnt-num/m)*p[0];
	}
	else{
		f[x]+=p[num%m]+(cnt-num/m-1)*p[0];
	}
	for(int i=(x-1)&x;i>0;i=(i-1)&x){
		f[x]=max(f[x],dfs(i)+dfs(x^i));
	}
	return f[x];
}
signed main(){
	qui();
	mem(f,-1);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=m;i++){
		cin>>p[i];
	}
	cout<<dfs((1<<n)-1);
	return 0;
}
/*
*/
