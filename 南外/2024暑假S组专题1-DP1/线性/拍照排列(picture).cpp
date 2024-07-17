#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define pii pair<int,int>
// #define int long long
#define in_vo inline void
#define in_ll inline long long
const int N=2e3+10;
using namespace std;
int n,m;

int a[10];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	while(1){
		cin>>n;
		memset(a,0,sizeof(a));
		if(n==0)break;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long f[a[1]+2][a[2]+2][a[3]+2][a[4]+2][a[5]+2];
		memset(f,0,sizeof(f));
		f[0][0][0][0][0]=1;
		for(int i1=0;i1<=a[1];i1++){
			// cout<<1<<endl;
			for(int i2=0;i2<=min(i1,a[2]);i2++){
				// cout<<2<<endl;
				for(int i3=0;i3<=min(i2,a[3]);i3++){
					// cout<<3<<endl;
					for(int i4=0;i4<=min(i3,a[4]);i4++){
						// cout<<4<<endl;
						for(int i5=0;i5<=min(i4,a[5]);i5++){
							// cout<<5<<endl;
							if(i1<a[1]){
								f[i1+1][i2][i3][i4][i5]+=f[i1][i2][i3][i4][i5];
							}
							if(i2<i1){
								f[i1][i2+1][i3][i4][i5]+=f[i1][i2][i3][i4][i5];
							}
							if(i3<i2){
								f[i1][i2][i3+1][i4][i5]+=f[i1][i2][i3][i4][i5];
							}
							if(i4<i3){
								f[i1][i2][i3][i4+1][i5]+=f[i1][i2][i3][i4][i5];
							}
							if(i5<i4){
								f[i1][i2][i3][i4][i5+1]+=f[i1][i2][i3][i4][i5];
							}
						}
					}
				}
			}
		}
		cout<<f[a[1]][a[2]][a[3]][a[4]][a[5]]<<'\n';
	}
	return 0;
}
/*
*/
