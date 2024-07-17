#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[5][N],ans=1e9+10;
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void f(int x,int y,int z){
	int l,r;
	l=1,r=2;
	for(;r<=n;r++){
		ans=min(ans,a[x][l]+a[y][r]-a[y][l]+a[z][n]-a[z][r]);
		if(a[x][r]-a[x][l]<a[y][r]-a[y][l]){
			l=r;
		}
	}
}
signed main(){
	quickcin();
	cin>>n;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			a[i][j]+=a[i][j-1];
		}
	}
//	cout<<ans<<endl;
	f(1,2,3);f(1,3,2);f(2,1,3);f(2,3,1);f(3,2,1);f(3,1,2);
	cout<<ans;
	return 0;
}
