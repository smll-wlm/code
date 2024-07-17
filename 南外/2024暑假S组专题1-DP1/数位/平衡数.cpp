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
const int N=1e1+15;
using namespace std;
int n,m;
int ans;
int a[N];
int f[N][1050][N*2][2];//f[i][j][k][fl]表示第i位，以j结尾，
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll dfs(int step,int pre,int exist,int fl,int fl_now){
	if(step<1){
		bool ff=0;
		for(int i=0;i<=9;i++){
			if(i%2==0&&((pre>>i)&1)==0&&((exist>>i/2)&1)==1)
				return 0;
			if(i%2==1&&((pre>>i)&1)==1)
				return 0;
			ff=1;
		}
		return ff;
	}
	if(fl==0&&f[step][pre][exist][fl_now]!=-1){
		return f[step][pre][exist][fl_now];
	}
	int r=0;
	if(fl){
		r=a[step];
	}
	else{
		r=9;
	}
	int res=0;
	for(int i=0;i<=r;i++){
		res+=dfs(step-1,
			(fl_now==1&&i==0)?pre:pre^(1<<i),
			(fl_now==1&&i==0||i%2==1)?exist:exist|(1<<i/2),
			fl&&i==r,
			fl_now&&i==0);
	}
	if(fl==0)f[step][pre][exist][fl_now]=res;
	return res;
}
in_ll solve(int x){
	int cnt=0;
	mem(a,0);mem(f,-1);
	while(x){
		a[++cnt]=x%10;
		x/=10;
	}
	return dfs(cnt,0,0,1,1);
}
signed main(){
	qui();
	cin>>n>>m;
	cout<<solve(m)-solve(n-1);
	return 0;
}
/*
*/
