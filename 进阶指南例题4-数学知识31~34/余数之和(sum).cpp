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
int ans=1e9,ans_gs;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}

signed main(){
	qui();
	cin>>n>>k;
	ans=n*k;
	for(int i=1,i1;i<=n;i=i1+1){
		i1= k/i ? min(k/(k/i),n) : n ;
		ans-=(k/i)*(i+i1)*(i1-i+1)/2;
	}
	cout<<ans;
	return 0;
}
/*
  k%i=k-floor(k/i)*i
=>原式=n*k-sum_{i=1}^n floor(k/i)*i
∵f(x)=k/x 单调递减
∴g(x)=floor(k/floor(k/x)),x∈[1,k]
  g(x)>=x
∴floor(k/g(x))<=floor(k/x),floor(k/g(x))>=floor(k/(k/floor(k/x)))=floor(k/x)
  floor(k/g(x))=floor(k/x)
=>任意i∈[x,floor(k/floor(k/x))],floor(k/i)相等
=>floor(k/i)*i=floor(k/x)*i,is the 等差数列,d=floor(k/x)
*/
