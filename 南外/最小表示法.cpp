#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#define int long long
const int N=1e6+10;
const int INF=45000;
using namespace std;
int n,q,k,ans;
string s;
char c[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	scanf("%s",c+1);
	int n=strlen(c+1);
	for(int i=1;i<=n;i++){
		c[n+i]=c[i];
	}
	int i=1,j=2;
	while(i<=n&&j<=n){
		int k=0;
		while(k<n&&c[i+k]==c[j+k]){
			k++;
		}
		if(k==n)break;
		if(c[i+k]>c[j+k]){
			i=i+k+1;
			if(i==j)i++;
		}
		else{
			j=j+k+1;
			if(i==j)j++;
		}
	}
	ans=min(i,j);
	for(int i=ans;i<ans+n;i++){
		printf("%c",c[i]);
	}
	return 0;
}
/*

*/
