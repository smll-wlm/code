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
int tr[N],a[N],anss[N];
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
	for(int i=x;i;i-=lowbit(i)){
		res+=tr[i];
	}
	return res;
}
signed main(){
	qui();
	cin>>n;
	add(1,1);
	for(int i=2;i<=n;i++){
		cin>>a[i];
		add(i,1);
	}
	for(int i=n;i>=1;i--){
		int l=1,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(ask(mid)<a[i]+1){
				l=mid+1;
			}
			else{
				anss[i]=mid;
				r=mid-1;
			}
		}
		add(anss[i],-1);
	}
	for(int i=1;i<=n;i++){
		cout<<anss[i]<<'\n';
	}
	return 0;
}
/*
*/
