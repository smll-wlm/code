#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<deque>
#define pii pair<int,int>
#define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=1e6+10;
using namespace std;
int n,m;
int a[N*2];
deque<int> q;
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[n+i]=a[i];
	}
	q.push_back(1);
	for(int i=1;i<=2*n;i++){
		while(q.size()&&q.front()<i-n/2)q.pop_front();
		ans=max(ans,a[i]+i+a[q.front()]-q.front());
		while(q.size()&&a[q.back()]-q.back()<a[i]-i)q.pop_back();
		q.push_back(i);
	}
	cout<<ans;
	return 0;
}
/*
*/
