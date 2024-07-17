#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<unordered_map>
#define pii pair<int,int>
// #define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=2e6+10;
using namespace std;
int n,m;
int a[N][3];
int fa[N],ms[N],cnt;
unordered_map<int,int> ma;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll fi_fa(int x){
	if(fa[x]==x)return x;
	return fa[x]=fi_fa(fa[x]);
}
in_vo merge(int x,int y){
	fa[fi_fa(x)]=fi_fa(y);
}
signed main(){
	qui();
	int T;
	cin>>T;
	while(T--){
		// cnt=0;
		cin>>n;
		m=n;
		n*=3;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(i%3){
				if(ma[x]==0){
					ma[x]=(++cnt);
				}
				a[i/3+1][i%3]=ma[x];
				fa[ma[x]]=ma[x];
			}
			else{
				ms[i/3]=x;
			}
		}
		int flag=0;
		for(int i=1;i<=m;i++){
			if(ms[i]){
				merge(a[i][1],a[i][2]);
			}
		}
		for(int i=1;i<=m;i++){
			if(!ms[i]){
				if(fi_fa(a[i][1])==fi_fa(a[i][2])){
					flag=1;
					cout<<"NO";
					break;
				}
			}
		}
		if(!flag){
			cout<<"YES";
		}
		cout<<"\n";
	}
	return 0;
}
/*
*/
