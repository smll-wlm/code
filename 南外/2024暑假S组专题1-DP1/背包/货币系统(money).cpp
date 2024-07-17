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
#define in_vo inline void
#define in_ll inline long long
const int N=1e3+10;
using namespace std;
int n,m;
int w[N],v[N];
int a[N];
int ans;
bitset<25010> f;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo init(){
	memset(a,0,sizeof(a));
	memset(v,0,sizeof(v));
	f.reset();f[0]=1;
	ans=0;
}
signed main(){
	qui();
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		m=n;
		init();
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(f[a[i]]==1){
				m--;
				continue;
			}
			for(int j=1;j<=a[n]/a[i]+1;j++){
				f|=f<<a[i];
			}
		}
		cout<<m<<endl;
	}
	return 0;
}
/*
*/
