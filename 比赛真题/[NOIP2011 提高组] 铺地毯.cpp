#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define fir first
#define sec second
#define int long long
#define in_vo inline void
#define in_ll inline long long
using namespace std;
const int N=1e4+10;
int n,m;
int ans;
struct node{
	int lx,rx,ly,ry;
}a[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main()
{
	qui();
	cin>>n;
	for(int i=1;i<=n;i++){
		int lenx,leny;
		cin>>a[i].lx>>a[i].ly>>lenx>>leny;
		a[i].rx=a[i].lx+lenx;
		a[i].ry=a[i].ly+leny;
	}
	int x,y;
	ans=-1;
	cin>>x>>y;
	for(int i=1;i<=n;i++){
		if(x>=a[i].lx&&x<=a[i].rx&&y>=a[i].ly&&y<=a[i].ry){
			ans=i;
		}
	}
	cout<<ans;
	return 0;
}
