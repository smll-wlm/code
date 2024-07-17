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
const int N = 1e4+10;
const int mod=998244353;
using namespace std;
int T,ans,n,m,k,x;
vector<int> v[100005]; 
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main()
{
	qui();
	cin>>T;
	while(T--){
		for(int i=0;i<=100000;i++)	v[i].clear();
		ans=0;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)	
		{
			for(int j=0;j<m;j++)
			{
				cin>>x;	
				v[i].push_back(x);
			}
			
		}
		if(k==1)
		{
			for(int j=0;j<m;j++)
				ans=max(ans,v[1][j]);
		}
		else
		{
			if(k%2==1)
			{
				ans=1e10+10;
				for(int i=1;i<=n;i++)
				{	
					int t=0;
					for(int j=0;j<m;j++)
						t=max(t,v[i][j]);
					ans=min(ans,t);	
				}
			}
			else 
			{	
				ans=0;
				for(int i=0;i<m;i++)
				{
					int t=1e9;
					for(int j=1;j<=n;j++)	t=min(t,v[j][i]);
					ans=max(t,ans);
				}
			}
			if(ans<v[1][0])	ans=v[1][0];	
		}
		cout<<ans<<'\n';
	}
	return 0;
}
