#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m;
int ans,ans2;
int pri[N],cnt;
bool chk(int x){
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
void quickcin(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
}
void init(){
	pri[++cnt]=2;pri[++cnt]=3;
	for(int i=4;i<=sqrt(n);i++){
		if(chk(i)){
			pri[++cnt]=i;
		}
	}
}
bool chk2(int mid,int l,int r){
	int cnt1=1;
	cnt1=(long long)cnt1*l;
	if(cnt1>n)return 0;
	cnt1=(long long)cnt1*l;
	if(cnt1>n)return 0;
	cnt1=(long long)cnt1*r;
	if(cnt1>n)return 0;
	cnt1=(long long)cnt1*r;
	if(cnt1>n)return 0;
	cnt1=(long long)cnt1*mid;
	return cnt1<=n;
}
signed main(){
	quickcin();
	cin>>n;
	init();
	for(int i=1;i<=cnt/4;i++){
		for(int j=i+2;j<=cnt;j++){
			int x=pri[i],y=pri[j];
			if(!chk2(pri[i+1],x,y))break;
			if(chk2(pri[j-1],x,y)){
				ans2=ans2+j-i-1;
			}
			else{
				for(int k=i+1;k<j;k++){
					if(chk2(pri[k],x,y))ans2++;
					else{
						break;
					}
				}
			}
			
		}
	}
	cout<<ans2;
	return 0;
}
