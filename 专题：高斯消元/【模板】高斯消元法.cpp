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
const double ep=1e-6;
using namespace std;
int n,m,p,q;
double a[N][N];
double x[N];
int ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
int gs(int n1,int m1){
	int c=0,r=0;
	
	for(r=0;r<n1&&c<m1;r++,c++){
		int maxr=r;
		for(int i=r+1;i<n1;i++){
			if(abs(a[i][c])>abs(a[maxr][c])){
				maxr=i;
			}
		}
		if(maxr!=r)swap(a[r],a[maxr]);
		if(fabs(a[r][c])<ep){
			r--;
			continue;
		}
		for(int i=r+1;i<n1;i++){
			if(fabs(a[i][c])>ep){
				double k=a[i][c]/a[r][c];
				// printf("%.2lf\n",k);
				for(int j=c;j<m1+1;j++) a[i][j]-=a[r][j]*k;
				a[i][c]=0;
			}
		}
	}
	
	for(int i=r;i<m1;i++){
		if(fabs(a[i][c])>ep)return -1;
	}
	if(r<m1)return m1-r;
	for(int i=m1-1;i>=0;i--){
		for(int j=i+1;j<m1;j++){
			a[i][m1]-=a[i][j]*x[j];
		}
		x[i]=a[i][m1]/a[i][i];
	}
	return 0;
}

signed main(){
	// qui();
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	m=n;
	int flag=gs(n,n);
	if(flag!=0){
		cout<<"No Solution";
		return 0;
	}
	// if(flag==-1){
	// 	cout<< -1;
	// 	return 0;
	// }
	// if(flag!=0){
	// 	cout<<0;
	// 	return 0;
	// }
	for(int i=0;i<n;i++){
		printf("%.2lf\n",x[i]);
	}
	return 0;
}
/*
*/
