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
const int N=1e6+10;
using namespace std;
int n,m,k,cnt,mod;
int ans;
int a[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}

signed main(){
	qui();
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			a[i]^=x;
			a[i]|=1<<i;
		}
		while(1){
			int x,y;
			cin>>x>>y;
			if(x==0&&x==y)break;
			a[y]|=1<<x;
		}
		
		ans=1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]>a[i]){
					swap(a[i],a[j]);
				}
			}
			if(!a[i]){
				ans=1<<(n-i+1);
				break;
			}
			if(a[i]==1){
				ans=0;
				break;
			}
			for(int j=n;j;j--){
				if(a[i]>>j &1){
					for(int k=1;k<=n;k++){
						if(i!=k&&(a[k]>>j &1)){
							a[k]^=a[i];
						}
					}
					break;
				}
			}
		}
		if(!ans){
			cout<<"Oh,it's impossible~!!\n";
		}
		else{
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/*
*/
