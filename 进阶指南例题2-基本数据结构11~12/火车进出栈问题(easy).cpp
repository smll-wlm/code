#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
const int N=1e6+10;
const int M=1e9;
using namespace std;
int n,m,len=1;
int a[N],sum[2*N];
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void prime(int b,int f){
	for(int j=2;j*j<=b&&b!=1;j++){
		while(b%j==0){
			sum[j]+=f;
			b/=j;
		}
	}
	if(b)sum[b]+=f;
}
void calc(int c){
	for(int i=1;i<=len;i++){
		a[i]*=c;
	}
	for(int i=1;i<=len;i++){
		a[i+1]+=a[i]/M;
		a[i]%=M;
	}
	while(a[len+1])len++;
}
signed main(){
	quickcin();
	cin>>n;
	a[1]=1;
	for(int i=1;i<=n;i++){
		prime(n+i,1);
	}
	for(int i=2;i<=n+1;i++){
		prime(i,-1);
	}
	for(int i=2;i<=2*n;i++){
		for(int j=0;j<sum[i];j++){
			calc(i);
		}
	}
	printf("%lld",a[len]);
	for(int i=len-1;i;i--){
		printf("%09lld",a[i]);
	}
	return 0;
}
