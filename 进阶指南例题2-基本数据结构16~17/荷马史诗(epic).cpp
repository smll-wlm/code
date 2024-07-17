#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define int long long
#define pii pair<int,int>
const int N=1e5+10;
using namespace std;
int n,m,k,cnt,ans;
int w[N];
priority_queue<pii,vector<pii>,greater<pii> > p;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		p.push({w[i],0});
	}
	while((p.size()-1)%(m-1)!=0){
		p.push({0,0});
	}
	while(p.size()>=m){
		int dep=-1,tep=0;
		for(int j=1;j<=m;j++){
			auto dx=p.top();
			p.pop();
			tep+=dx.first;
			dep=max(dep,dx.second);
		}
		p.push({tep,dep+1});
		ans+=tep;
	}
	cout<<ans<<endl<<p.top().second;
	return 0;
}
