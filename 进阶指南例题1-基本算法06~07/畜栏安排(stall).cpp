#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector>
#define int long long
using namespace std;
const int N=5e4+10;
int i,j,n,m;
int b[1000010];
struct node{
	int l,r,x;
}a[N];
int ans;
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
signed main()
{
	quickcin();
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		b[a[i].l]++;
		b[a[i].r+1]--;
	}
	int ans=0;
	for(i=1;i<=1000010;i++){
		b[i]+=b[i-1];
		ans=max(ans,b[i]);
	}
	cout<<ans;
	return 0;
}
