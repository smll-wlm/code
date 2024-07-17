#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<cstring>
#include<string>
#define int long long
const int N=1e6+10;
const int P=131;
using namespace std;
int n,m;
int ans;
unsigned long long p[N],a1[N],a2[N];
char s1[N],s2;
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void init(){
	p[0]=1;
	for(int i=1;i<N;i++){
		p[i]=p[i-1]*P;
	}
}
unsigned long long H1(int i,int j){
	return (a1[j]-a1[i-1]*p[j-i+1]);
}
unsigned long long H2(int i,int j){
	return (a2[i]-a2[j+1]*p[j-i+1]);
}
signed main(){
	quickcin();
	int cnt=1;
	init();
	while(1){
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		scanf("%s",s1+1);
		if(s1[1]=='E')break;
		int len=strlen(s1+1);
		ans=0;
		for(int i=1;i<=len;i++){
			a1[i]=a1[i-1]*P+s1[i]-'a'+1;
		}
		for(int i=len;i>=1;i--){
			a2[i]=a2[i+1]*P+s1[i]-'a'+1;
		}
		int l,r;
		for(int i=1;i<=len;i++){
			//奇数
			l=0,r=min(i-1,len-i);
			while(l<r){
				int mid=(l+r+1)>>1;
				if(H1(i-mid,i-1)==H2(i+1,i+mid)){
					l=mid;
				}
				else{
					r=mid-1;
				}
			}
			//偶数
			ans=max(l<<1|1,ans);
			l=0,r=min(i-1,len-i+1);
			while(l<r){
				int mid=(l+r+1)>>1;
				if(H1(i-mid,i-1)==H2(i,i+mid-1)){
					l=mid;
				}
				else{
					r=mid-1;
				}
			}
			ans=max(ans,l<<1);
		}
		printf("Case %lld: %lld\n",cnt++,ans);
	}
	return 0;
}
