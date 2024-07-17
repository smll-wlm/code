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
int tr1[N],tr2[N],a[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll lowbit(int x){
	return x&(-x);
}
in_vo add(int x,int y){
	for(int i=x;i<=n;i+=lowbit(i)){
		tr1[i]+=y;
		tr2[i]+=x*y;
	}
}
in_ll ask(int x){
	int res=0;
	for(int i=x;i>0;i-=lowbit(i)){
		res+=(x+1)*tr1[i]-tr2[i];
	}
	return res;
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		add(i,a[i]-a[i-1]);
	}
	while(m--){
		char op;
		cin>>op;
		if(op=='Q'){
			int x,y;
			cin>>x>>y;
			cout<<ask(y)-ask(x-1)<<"\n";
		}
		else{
			int x,y,d;
			cin>>x>>y>>d;
			add(x,d);
			add(y+1,-d);
		}
	}
	return 0;
}
/*
*/
