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
using namespace std;
int n,q,k;
int ans=1e9,ans_gs;
int js;
int a[11]={0,2,3,5,7,11,13,17,19,23,29};
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void dfs(int step,int pre,unsigned long long mul,int ans1){
	if(mul>n||mul==0)return;
	if(step==11||pre==0){
		if(ans1>ans_gs||(ans1==ans_gs&&ans>mul)){
			ans=mul;
			ans_gs=ans1;
		}
		return;
	}
	int mul1=mul;
	for(int i=0;i<=pre;i++){
		if(mul1>n)return;
		dfs(step+1,pre-i,mul1,ans1*(i+1));
		js++;
		mul1*=a[step];
	}
}
signed main(){
	qui();
	cin>>n;
	for(int i=31;i>=1;i--){
		if(pow(2,i)>n)continue;
		dfs(1,i,1,1);
	}
	cout<<ans;
	return 0;
}
/*

*/
