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
const int mod=10007;
using namespace std;
int n,m,p,q;
int ans;
struct node{
	int l,r;
	int nl,nr;
}a[N];
int b[N],d[N],s[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}

signed main(){
	qui();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		b[i]=a[i].l;b[i+n]=a[i].r;
	}
	sort(b+1,b+1+2*n);
	auto len1=unique(b+1,b+1+2*n);
	for(int i=1;i<=n;i++){
		a[i].nl=lower_bound(b+1,len1,a[i].l)-b;
		a[i].nr=lower_bound(b+1,len1,a[i].r)-b;
	}
	for(int i=1;i<=n;i++){
		d[a[i].nl+1]++;
		d[a[i].nr+1]--;
	}
	for(int i=1;i<=(len1-b-1);i++){
		s[i]=s[i-1]+d[i];
	}
	for(int i=1;i<=(len1-b-1);i++){
		int l,r;
		if(s[i]!=0&&s[i-1]==0)l=i-1;
		if(s[i]!=0&&s[i+1]==0){
			r=i;
			ans+=b[r]-b[l];
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
