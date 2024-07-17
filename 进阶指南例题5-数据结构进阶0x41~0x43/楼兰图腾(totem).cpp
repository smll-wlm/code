#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<unordered_map>
#define pii pair<int,int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=3e5+10;
using namespace std;
int n,m;
int maxx;
int tr[N],a[N];
int l[N],r[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll lowbit(int x){
	return x&(-x);
}
in_vo add(int x,int y){
	for(int i=x;i<=n;i+=lowbit(i)){
		tr[i]+=y;
	}
}
in_ll ask(int x){
	int res=0;
	for(int i=x;i>0;i-=lowbit(i)){
		res+=tr[i];
	}
	return res;
}
in_vo solve1(){
	memset(tr,0,sizeof(tr));
	for(int i=n;i;i--){
		r[i]=ask(maxx)-ask(a[i]);
		add(a[i],1);
	}
	memset(tr,0,sizeof(tr));
	for(int i=1;i<=n;i++){
		l[i]=ask(maxx)-ask(a[i]);
		add(a[i],1);
	}
}
in_vo solve2(){
	memset(tr,0,sizeof(tr));
	for(int i=n;i;i--){
		r[i]=ask(a[i]-1);
		add(a[i],1);
	}
	memset(tr,0,sizeof(tr));
	for(int i=1;i<=n;i++){
		l[i]=ask(a[i]-1);
		add(a[i],1);
	}
}
in_ll _ans(){
	int anss=0;
	for(int i=1;i<=n;i++){
		anss+=l[i]*r[i];
	}
	return anss;
}
signed main(){
	qui();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	solve1();
	cout<<_ans()<<' ';
	solve2();
	cout<<_ans();
	return 0;
}
/*
*/
