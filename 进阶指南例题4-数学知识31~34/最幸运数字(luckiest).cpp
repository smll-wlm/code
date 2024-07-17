#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define int long long
const int N=1e6+10;
const int mod=1e18;
using namespace std;
int n,m,k,cnt;
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
int calc_add(int a,int b,int p){
	int anss=0;
	while(b){
		if(b&1){
			anss=(anss+a)%p;
		}
		a=a*2%p;
		b>>=1;
	}
	return anss;
}
int calc_mul(int a,int b,int p){
	int anss=1;
	a%=p;
	while(b){
		if(b&1){
			anss=calc_add(anss,a,p);
		}
		a=calc_add(a,a,p);
		b>>=1;
	}
	return anss;
}
int get_phi(int x){
	int res=x;
	for(int i=2;i<=x/i;i++){
		if(x%i==0){
			while(x%i==0)x/=i;
			res=res/i*(i-1);
		}
	}
	if(x>1)res=res/x*(x-1);
	return res;
}
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}
signed main(){
	qui();
	int t1=0;
	while(1){
		t1++;
		cin>>n;
		if(n==0)break;
		cout<<"Case "<<t1<<": ";
		int n1=8;
		int d=gcd(n1,n);
		int t=(long long)9*n/d;
		int phi1=get_phi(t);
		ans=1e18;
		if(t%2==0||t%5==0){
			ans=0;
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=phi1/i;i++){
			if(phi1%i==0){
				if(calc_mul(10,i,t)%t==1){
					ans=min(ans,i);
				}
				if(calc_mul(10,phi1/i,t)%t==1){
					ans=min(ans,phi1/i);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
欧拉公式：
phi(n)=1*(1-1/p1)*(1-1/p2)...*(1-1/pn)
p1,p2...pn为n的质因数
*/
