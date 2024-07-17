#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector>
#define int long long
using namespace std;
int a[1000010];
int t,l,r;
int i,j,n,m;
int ans;
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
bool check(int mid){
	int cnt=0;
	for(i=1;i<=n;i++){
		if(a[i]>mid){
			cnt+=a[i]-mid;
		}
	}
	return cnt>=m;
}
signed main()
{
	quickcin();
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=0,r=1e9;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
