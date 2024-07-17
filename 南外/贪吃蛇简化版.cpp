#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
const int N=1e3+10;
const int P=131;
using namespace std;
int n,m;
int ans,a[1010][1010],zt=1,l[1010],r[1010],sum[1010];
char c;
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void pl(int i){
	for(int j=1;j<=m;j++){
		if(a[i][j]==1){
			l[i]=j;
			return;
		}
	}
}
void pr(int i){
	for(int j=m;j>=1;j--){
		if(a[i][j]==1){
			r[i]=j;
			return;
		}
	}
}
signed main(){
	quickcin();
	cin>>n>>m;
	memset(l,0x3f3f3f,sizeof(l));
	memset(r,0,sizeof(r));
	int f1=0x3f3f3f,f2=0;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		for(int j=1;j<=m;j++){
			if(s[j-1]=='J'){
				a[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		pl(i);pr(i);
	}
	int it=1,cnt=1;
	for(int i=1;i<=n;i++){
		if(r[i]==f2){
			cnt++;
			
		}
		else{
			break;
		}
	}
//	cnt--;
//	cout<<cnt<<endl;
	for(int i=n;i>=cnt;i--){
		int ans1=ans;
		if(zt){
			r[i]=max(r[i],r[i-1]);
			r[i-1]=max(r[i],r[i-1]);
			if(r[i]==0)ans+=0;
			else{
				ans=ans+abs(r[i]-it);
				if(ans>1000010||abs(ans1-ans)==it){
					ans-=abs(r[i]-it);
					zt=1-zt;
					continue;
				}
				it=r[i];
			}
		}
		else{
			l[i]=min(l[i],l[i-1]);
			l[i-1]=min(l[i],l[i-1]);
			if(l[i]==f1)ans+=0;
			else{
				ans=ans+abs(it-l[i]);
				if(ans>1000010){
					ans-=abs(it-l[i]);
					zt=1-zt;
					continue;
				}
				it=l[i];
			}
			
		}
		zt=1-zt;
//		cout<<ans<<endl;
	}
//	cout<<ans<<endl;
//	if(cnt!=1)cnt;
	cout<<ans+n-cnt;
	return 0;
	
}
/*
10 10
..........
.......J..
.......J..
..J.......
......JJ..
..........
..........
.......J..
.J........
Z........J
*/
