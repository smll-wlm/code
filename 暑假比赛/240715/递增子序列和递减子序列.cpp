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
const int N = 1e5 + 10;
using namespace std;
int n, m;
int ans;
int a[N];
int maxh;
void qui() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
signed main() {
	qui();
	int T;
	cin>>T;
	while(T--){
		int x,y;
		cin>>n>>x>>y;
		mem(a,0);
		if(x+y-1>n||x*y<n){
			cout<<"NO\n";
			continue;
		}
		else{
			cout<<"YES\n";
		}
		int cnt=1;
		for(int i=n-y+1;i<=n;i++){
			a[i]=n-cnt+1;
			cnt++;
		}
		x--;
		int flag=0;
		int sy=n-y;
		cnt=n-cnt+1;
		while(sy>x){
			flag++;
			if(sy-y>=x){
				x--;
				int tt=0;
				for(int i=sy-y+1;i<=sy;i++){
					a[i]=sy-tt;
					tt++;
				}
				sy-=y;
				cnt-=y;
			}
			else{
				x--;
				int tt=0;
				for(int i=x+1;i<=sy;i++){
					a[i]=sy-tt;
					tt++;
					cnt--;
				}
				sy-=y;
			}
		}
		for(int i=1;i<=x;i++){
			a[i]=i;
		}
		if(flag==0)
			for(int i=x;i<=n-y;i++){
				a[i]=cnt;
				cnt--;
			}
		for(int i=1;i<=n;i++){
			cout<<a[i];
			if(i!=n){
				cout<<' ';
			}
		}
		cout<<'\n';
	}
	return 0;
}
/*
*/
