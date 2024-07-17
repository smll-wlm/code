#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define int long long
#define in_vo inline void
#define in_ll inline long long
using namespace std;
const int N=1e6+10;
int n,m;
int ans;
int cnt,a[20],b[5];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	scanf("%lld",&n);
	while(n!=0){
		a[++cnt]=n%10;
		ans+=n%10;
		b[a[cnt]%3]++;
		n/=10;
	}
	int l=ans%3;
	if(l!=0&&cnt==1){
		cout<<-1;
		return 0;
	}
	if(l==1){
		if(b[1]==0&&b[2]<2){
			ans=-1;
		}
		else{
			ans=b[1]?1:2;
		}
	}
	if(l==0){
		ans=0;
	}
	if(l==2){
		if(b[2]==0&&b[1]<2){
			ans=-1;
		}
		else{
			ans=b[2]?1:2;
		}
	}
	if(cnt-ans==0)ans=-1;
	printf("%lld",ans);
	return 0;
}
