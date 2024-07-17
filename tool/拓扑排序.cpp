#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=1e6+10;
const int INF=1e9;
using namespace std;
int n,m,k,cnt,mod;
int ans;
int rd[N],b[N];
queue<pair<int,int> > q1,q;
vector<int> v[N];
vector<pair<int,int> > tuo;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void tuopu(int st,int ed){
	q=q1;
	while(!q.empty()){
		pair<int,int> t=q.front();
		q.pop();
		tuo.push_back({t.fir,t.sec+1});
		for(auto y:v[t.fir]){
			rd[y]--;
			if(rd[y]==0){
				q.push({y,t.sec+1});
			}
		}
	}
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		rd[y]++;
	}
	for(int i=1;i<=n;i++){
		if(!rd[i])q1.push({i,0});
	}
	tuopu(1,n);
	for(auto it:tuo){
		b[it.fir]=it.sec;
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<endl;
	}
	return 0;
}
/*
*/
