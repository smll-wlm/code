#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<cstring>
#include<map>
#include<string>
#define int long long
const int N=1e6+10;
const int P=46350;
using namespace std;
int n,m;
int ans;
int ma[110][110];
int a[N],pr[N];
int t[N];
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

signed main(){
	quickcin();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		ma[x][y]=1;
		ma[y][x]=1;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				if(ma[i][j]==1&&ma[i][k]==1&&ma[j][k]==1){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*

*/
