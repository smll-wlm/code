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
const int N=1e5+10;
using namespace std;
int n,m;
int cnt,nowt;
struct node{
	int fr,bc,num,ad;
	int fl;
}a[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i].num=x;a[i].ad=i;
		a[i].fr=i-1;a[i].bc=i+1;
	}
	a[1].fr=a[n].ad;a[n].bc=a[1].ad;
	nowt=1;cnt=n;
	while(cnt){
		for(int i=1;i<m;i++){
			nowt=a[a[nowt].bc].ad;
		}
		cout<<nowt<<' ';
		a[a[nowt].fr].bc=a[a[nowt].bc].ad;
		a[a[nowt].bc].fr=a[a[nowt].fr].ad;
		nowt=a[a[nowt].bc].ad;
		cnt--;
	}
	return 0;
}
/*
*/
