#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
int a[300010],sum[300010],i,j,n,m;
deque<int>q;
int ans=-1e9;
signed main(){
	IOS;TIE;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	q.push_back(0);
	for(i=1;i<=n;i++){
		while(q.size()&&q.front()<i-m){
			q.pop_front();
		}
		ans=max(ans,a[i]-a[q.front()]);
		while(q.size()&&a[q.back()]>=a[i]){
			q.pop_back();
		}
		q.push_back(i);
	}
	cout<<ans;
	return 0;
}
