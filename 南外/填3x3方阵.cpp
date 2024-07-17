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
#define ll long long 
#define in_vo inline void
#define in_ll inline long long
const int N=1e7+10;
using namespace std;
int n,m;
int a[10],b[10];
int ma[10][10];
int numa,numb,ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>a[1]>>a[2]>>a[3]>>b[1]>>b[2]>>b[3];
	numa=a[1]+a[2]+a[3];
	numb=b[1]+b[2]+b[3];
	if(numa!=numb){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=30;i++){
		for(int j=1;j<=30;j++){
			for(int k=1;k<=30;k++){
				for(int l=1;l<=30;l++){
					
					ma[1][3]=a[1]-i-j;
					ma[2][3]=a[2]-k-l;
					ma[3][1]=b[1]-i-k;
					ma[3][2]=b[2]-j-l;
					ma[3][3]=a[3]-ma[3][1]-ma[3][2];
					
					if(ma[1][3]>0&&ma[2][3]>0&&ma[3][1]>0&&ma[3][2]>0&&ma[3][3]>0)
						if(ma[1][3]+ma[2][3]+ma[3][3]==b[3]){
							ans++;	
//							printf("%lld %lld %lld %lld %lld\n",i,j,k,l,ans);
						}
					
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
