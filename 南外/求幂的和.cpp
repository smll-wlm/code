#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n,m,k;
int ans=1,x[1000010],v[1000010];
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int calc(int a,int b,int p){
	int cnt=1;
	for(int i=1;i<=b;i++){
		cnt=cnt*a;
		int x=cnt/m;
		cnt-=x*m;
		a=a*a;
		x=a/m;
		a-=x*m;
	}
	return cnt;
}
signed main(){
	quickcin();
	cin>>n>>k>>m;
	for(int i=2;i<=n;i++){
		if(v[i]){
			x[i]=x[v[i]]*x[i/v[i]]%m;
			ans=(ans+x[i])%m;
		}
		else{
			x[i]=calc(i,k,m);
			ans=(ans+x[i]);
			ans%=m;
			for(int j=i;j<=n;j+=i){
				v[j]=i;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
