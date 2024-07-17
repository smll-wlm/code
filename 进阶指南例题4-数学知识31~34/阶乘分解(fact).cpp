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
int calc(int p){
	int tot=0;
	for(int i=1;i<=n;i++){
		if(pow(p,i)>n)break;
		tot+=floor(n/pow(p,i));
	}
	return tot;
}
signed main(){
	qui();
	init();
	cin>>n;
	for(int i=1;i<=cnt;i++){
		ans=calc(pri[i]);
		if(ans==0)continue;
		else{
			cout<<pri[i]<<' '<<ans<<endl;
		}
	}
	return 0;
}
/*

*/
