#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<bitset>
#define pii pair<int,int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=1e5+10;
using namespace std;
int n,m;
bitset<1000010> f;
int ans,num1[1010],tot;
struct node{
	int val,num;
}a[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	f[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].val>>a[i].num;
	}
	for(int i=1;i<=n;i++){
		int t=1,z=a[i].num;
		tot=0;
		memset(num1,0,sizeof(num1));
		for(t;t<=z;t<<=1){
			num1[++tot]=t*a[i].val;
			z-=t;
		}
		num1[++tot]=z*a[i].val;
		for(int j=1;j<=tot;j++)
			f|=f<<num1[j];
	}
	for(int i=1;i<=m;i++){
		cout<<f[i];
	}
	return 0;
}
/*
*/
