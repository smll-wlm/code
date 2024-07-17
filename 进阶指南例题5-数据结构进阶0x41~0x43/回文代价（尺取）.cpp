#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define pii pair<int,int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=1e6+10;
using namespace std;
int n,m;
int ans,cnt;
int a[N],f[N];
vector<int> v[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		cnt+=i/2*(n-i+1);
	}
	for(int i=1;i<=n;i++){
		int l=0,r=v[i].size()-1;
		while(l<r){
			if(v[i][l]<n+1-v[i][r]){
				cnt-=(r-l)*v[i][l];
				l++;
			}
			else{
				cnt-=(r-l)*(n+1-v[i][r]);
				r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
/*
*/
