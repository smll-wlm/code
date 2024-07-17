#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#define fir first
#define sec second
#define int long long
const int N=1e6+10;
using namespace std;
int n,m,k,ans[N];
int a[N];
int cnt;
pair<int,int> com[N];
priority_queue<pair<int,int> > out;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}

signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int j=1;j<=n;j++){
		com[j].fir=a[j];
		com[j].sec=0;
		int y=j;
		out.push({-com[y].fir,y});
	}
	while(cnt<=m){
		int x=-out.top().fir;
		int y=out.top().sec;
		out.pop();
		if(x!=ans[cnt])ans[++cnt]=x;
		com[y].fir=a[y]*ans[++com[y].sec];
		out.push({-com[y].fir,y});
	}
	cout<<ans[m];
	return 0;
}
