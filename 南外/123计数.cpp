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
int a[N];
struct node{
	int n1,n2,n3;
}num[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[i].n1=num[i-1].n1;num[i].n2=num[i-1].n2;
		num[i].n3=num[i-1].n3;
		if(a[i]==1)num[i].n1++;
		if(a[i]==2)num[i].n2++;
		if(a[i]==3)num[i].n3++;
	}
	while(m--){
		int x,y;
		cin>>x>>y;
		cout<<num[y].n1-num[x-1].n1<<' ';
		cout<<num[y].n2-num[x-1].n2<<' ';
		cout<<num[y].n3-num[x-1].n3<<'\n';
	}
	return 0;
}
/*
*/
