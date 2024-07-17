#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
#include<unordered_map>
#include <map>
#define pii pair<int, int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=5e5+10;
int  T,fa[N],dep[N],n,d[N];
int ans,sum,f[N];
vector<int> v[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo init(){
	for(int i=0;i<=n;i++){
		v[i].clear();
		f[i]=dep[i]=d[i]=fa[i]=0;
	}
	sum=0;ans=0;
}
in_vo dfs(int x)
{
	if(x==1)dep[x]=1;
	else{
		dep[x]=dep[fa[x]]+1;
	}
	f[x]=1;
	for(auto it:v[x]){
		dfs(it);
		f[x]+=f[it];
	}
	sum+=f[x];
}
in_vo dfs1(int x)
{
	d[x]=d[fa[x]]+f[x];
	for(auto it:v[x])
	{
		dfs1(it);
	}
	return ;
}
signed main()
{
	qui();
	cin>>T;
	while(T--){
		cin>>n;	
		init();
		for(int i=2;i<=n;i++)
		{
			cin>>fa[i];
			v[fa[i]].push_back(i);
		}
		dfs(1);
		dfs1(1);
		int maxn=-0x3f;
		for(int i=1;i<=n;i++){
			maxn=max(n*dep[i]-d[i],maxn);
		}
		cout<<sum+maxn<<'\n';
	}
	return 0;
}
