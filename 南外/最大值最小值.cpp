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
#define in_vo inline void
#define in_ll inline long long
const int N=2e5+10;
using namespace std;
int n,m,gs;
int ans;
int num1,num2;
int a[N],b[N];
int gs1,gs2;
struct node{
	int f,res;
	int l1,r1;
};
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
node l,r,d[N];
int nn1,nn2;
signed main(){
	qui();
	cin>>n>>num1>>num2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==num1)b[i]=1,gs1++;
		if(a[i]==num2)b[i]=2,gs2++;
	}
	l.res=1,r.res=1;
	for(int i=1;i<=n+1;i++){
		if(a[i]>=num2&&a[i]<=num1){
			if(b[i]){
				if(a[i]==num1){
					nn1++;
				}
				if(a[i]==num2||num1==num2){
					nn2++;
				}
			}
		}
		else{
			r.res=i-1;
			if(nn1>0&&nn2>0){
				int cnt=0,j_l=0;
				d[0].l1=l.res-1;
				for(int j=l.res;j<=r.res;j++){
					if(b[j]){
						l.f=a[j];
						j_l=l.res;
						break;
					}
				}
				for(int j=l.res;j<=r.res;j++){
					if(b[j]){
						if(l.f==a[j]){
							j_l=j;
						}
						if(l.f!=a[j]||num1==num2){
							d[++cnt].l1=j_l;
							d[cnt].r1=j;
							l.f=a[j];
							j_l=j;
						}
					}
				}
				for(int j=1;j<=cnt;j++){
					ans=ans+(d[j].l1-d[j-1].l1)*(r.res-d[j].r1+1);
				}
			}
			l.res=i+1;
			nn1=0;nn2=0;
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
