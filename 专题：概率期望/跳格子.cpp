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
const int N=1e2+10;
const int mod=1e9+9;
using namespace std;
int n,m,p,q;
double ans;
int t1,t2,zs;
char c[20];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	// qui();
	scanf("%s",c);
	n=strlen(c);
	cin>>m;
	for(int i=0;i<=(1<<n);i++){
		int num=i;
		t1=0,t2=0;
		for(int j=1;j<=n;j++){
			if(j&1){
				t1+=num&1;
				num>>=1;
			}
			else{
				t2+=num&1;
				num>>=1;
			}
		}
		if(t1+t2!=m)continue;
		zs++;
		ans=ans+(t1%2)+(t2%2);
		// printf("%.2lf\n",ans);
	}
	printf("%.2lf",ans/zs);
	return 0;
}
/*
*/
