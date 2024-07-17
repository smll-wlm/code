#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector>
#define int long long
using namespace std;
const int P=998244353;
const int N=4e5+10;
int n,m,k;
int pw[N],inv[N],f[N];
int ans;
int cnt;
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int quick(int a,int b,int p){
	int aa=1;
	while(b!=0){
		if(b&1){
			aa=aa*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return aa;
}
int calc(int a,int b){
	return f[a]*inv[b]%P*inv[a-b]%P;
}
signed main()
{
	quickcin();
	cin>>n>>m>>k;
	f[0]=pw[0]=1;
	for(int i=1;i<=n*2;i++){
		f[i]=(f[i-1]*i)%P;
	}
	inv[2*n]=quick(f[2*n],P-2,P);
	for(int i=2*n;i>=1;i--){
		inv[i-1]=inv[i]*i%P;
	}
	for(int i=1;i<=n;i++){
		pw[i]=pw[i-1]*(m-1)%P;
	}
	for(int i=0;i<=k;i++){
		int num=n-i;
		int ans1=pw[num-1]*m%P;
		(ans1*=calc(num+i-1,i) )%=P;
		ans=(ans+ans1)%P;
	}
	cout<<ans;
	return 0;
}
/*
本题可以视为求逆元数量，因此快速幂的b设置为P-2
*/
