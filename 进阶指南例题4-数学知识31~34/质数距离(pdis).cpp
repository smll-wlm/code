#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#define int long long
const int N=1e6+10;
using namespace std;
int n,q,k;
int ans;
int pri[N],cnt,bj[N],p[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
bool chk(int x){
	if(x==2||x==3)return 1;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0)return 0;
	}
	return 1;
}
void init(){
	for(int i=2;i<=N;i++){
		if(chk(i)){
			pri[++cnt]=i;
		}
	}
}
signed main(){
	qui();
	init();
	int l,r;
	while(cin>>l>>r){
		memset(bj,0,sizeof(bj));
		if(l==1)bj[0]=1;
		for(int i=1;i<=cnt;i++){
			for(int j=ceil(l/pri[i]);j<=floor(r/pri[i]);j++){
				if(j!=1){
					bj[pri[i]*j-l]=1;
				}
			}
		}
		int las=0,maxn=0,minn=1e9;
		int ans1_l,ans1_r,ans2_l,ans2_r;
		for(int i=l;i<=r;i++){
			if(bj[i-l]==0){
				if(las!=0){
					if(maxn<i-las){
						ans1_l=las;
						ans1_r=i;
						maxn=i-las;
					}
					if(minn>i-las){
						ans2_l=las;
						ans2_r=i;
						minn=i-las;
					}
				}
				las=i;
			}
		}
		if(maxn==0&&minn==1e9){
			cout<<"There are no adjacent primes.\n";
		}
		else{
			cout<<ans2_l<<','<<ans2_r<<" are closest, ";
			cout<<ans1_l<<','<<ans1_r<<" are most distant.\n";
		}
	}
	return 0;
}
/*

*/
