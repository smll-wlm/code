#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define pii pair<int,int>
#define int long long
#define ll long long 
#define in_vo inline void
#define in_ll inline long long
const int N=1e5+10;
const int mod=1e9+7;
using namespace std;
int n,m;
int inv[N],p[N];
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll calc(ll a,ll b){
	if(b<0)return 1;
	int aa=1;
	while(b){
		if(b&1){
			aa=aa*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return aa;
}
in_ll C(int m1,int n1){
	if(m1<0||n1<0||m1<n1)return 0;
	m1%=mod;
	if(m1==0||n1==0)return 1;
	int cot=1;
	for(int i=0;i<n1;i++){
		cot=cot*(m1-i)%mod;
	}
	for(int i=1;i<=n1;i++){
		cot=cot*inv[i]%mod;
	}
	return cot;
}
void init(){
	for(int i=1;i<=20;i++){
		inv[i]=calc(i,mod-2);
	}
}
signed main(){
	qui();
	init();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=0;i<1<<n;i++){
		if(i==0)ans=(ans+C(n+m-1,n-1))%mod;
		else{
			int t=n+m;
			int p1=0;
			for(int j=0;j<n;j++){
				if(i>>j&1){
					p1++;
					t-=p[j+1];
				}
			}
			t-=p1+1;
			if(p1&1){
				ans=(ans-C(t,n-1))%mod;
			}
			else{
				ans=(ans+C(t,n-1))%mod;
			}
		}
		
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}
/*
*/
