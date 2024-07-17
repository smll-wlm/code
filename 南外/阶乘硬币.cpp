#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector>
#define int long long
using namespace std;
int n,m;
int ans;
int cnt,a[110];
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void init(){
	a[1]=1;
	for(int i=2;i<=10;i++){
		a[i]=a[i-1]*i;
	}
}
signed main()
{
	quickcin();
	init();
	cin>>n;
	for(int i=10;i>=1;i--){
		while(n>=a[i]){
			ans++;
			n-=a[i];
		}
	}
	cout<<ans;
	return 0;
}
