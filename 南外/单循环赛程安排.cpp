#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=1e3+10;
using namespace std;
int n,m,k,cnt,mod;
int ans;
int a[N][N],b[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++){
			int x;
			cin>>x;
			a[i][j]=x;
		}
	}
	int zs=n*(n-1);
	while(zs){
		ans++;
		memset(b,0,sizeof(b));
		int flag=0;
		for(int i=1;i<=n;i++){
			int ne=a[i][a[i][0]+1];
			if(a[ne][a[ne][0]+1]==i&&b[i]==0&&b[ne]==0){
				a[ne][0]++;a[i][0]++;
				b[i]=1;b[ne]=1;
				zs-=2;
				flag=1;
			}
		}
		if(flag==0){
			ans=-1;
			break;
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
