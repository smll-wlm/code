#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define int long long
const int N=1e3+10;
using namespace std;
int n,m,k,cnt;
int ans,p[N],pri[N],vis[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void phi(int x){
	p[1]=1;
	for(int i=2;i<=x;i++){
		p[i]=i;
	}
	for(int i=2;i<=x;i++){
		if(p[i]==i){
			for(int j=i;j<=x;j+=i){
				p[j]=p[j]/i*(i-1);
			}
		}
	}
}
signed main(){
	qui();
	int T;
	cin>>T;
	for(int t1=1;t1<=T;t1++){
		cin>>n;
		ans=0;
		phi(n);
		for(int i=2;i<=n;i++){
			ans+=p[i]*2;
		}
		cout<<t1<<' '<<n<<' '<<ans<<endl;
	}
	return 0;
}
/*
欧拉公式：
phi(n)=1*(1-1/p1)*(1-1/p2)...*(1-1/pn)
p1,p2...pn为n的质因数
*/
