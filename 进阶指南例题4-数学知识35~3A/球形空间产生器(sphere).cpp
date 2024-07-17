#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=1e6+10;
using namespace std;
int n,m,k,cnt,mod;
int ans;
double a[20][20],b[20],c[20][20];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}

signed main(){
	qui();
	scanf("%lld",&n);
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n;j++){
			scanf("%lf",&a[i][j]);
		}
	}
	//c:系数矩阵 b：常熟
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=2*(a[i][j]-a[i+1][j]);
			b[i]+=a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(fabs(c[j][i])>1e-8){
				for(int k=1;k<=n;k++){
					swap(c[i][k],c[j][k]);
				}
				swap(b[i],b[j]);
			}
		}
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			double ra=c[j][i]/c[i][i];
			for(int k=i;k<=n;k++){
				c[j][k]-=c[i][k]*ra;
			}
			b[j]-=b[i]*ra;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%.3lf ",fabs(b[i]/c[i][i]));
	}
	return 0;
}
/*
*/
