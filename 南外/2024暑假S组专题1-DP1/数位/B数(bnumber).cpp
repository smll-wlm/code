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
const int N=15+10;
using namespace std;
int n,m;
int ans;
int a[N],cnt;
int f[N][N][N][2];//f[i][j][k][fl]表示第i位，%13的余数j，以k结尾，fl存在13
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll dfs(int step,int mod,int pre,int fl,int fl_now){
	if(step==0){
		if(fl_now==1&&mod==0)return 1;
		return 0;
	}
	if(fl==0&&f[step][mod][pre][fl_now]!=-1){
		return f[step][mod][pre][fl_now];
	}
	int r=0;
	if(fl==1){
		r=a[step];
	}
	else{
		r=9;
	}
	int res=0;
	for(int i=0;i<=r;i++){
		res=res+dfs(step-1,(mod*10+i)%13,i,fl&&(i==r),fl_now||(pre==1&&i==3));
	}
	if(fl==0)f[step][mod][pre][fl_now]=res;
	return res;
}
signed main(){
	qui();
	cin>>n;
	m=n;
	while(n){
		a[++cnt]=n%10;
		n/=10;
	}
	memset(f,-1,sizeof(f));
	cout<<dfs(cnt,0,0,1,0);
	return 0;
}
/*
*/
