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
const int N=1e5+10;
const int mod=10007;
using namespace std;
int n,m,p,q;
int ans;
int h1,h2,m1,m2;
int h_new,m_new,ans_h,ans_m;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}

signed main(){
	qui();
	cin>>n>>m;
	h1=n/10;h2=n%10;
	m1=m/10;m2=m%10;
	h_new=h1*10+m1;
	m_new=h2*10+m2;
	ans_h=n;ans_m=m;
	if(ans_h==24&&ans_m==0){
		cout<<ans_h<<' '<<ans_m;
		return 0;
	}
	while(!(h_new>=0&&h_new<24&&m_new>=0&&m_new<60&&ans_h<24&&ans_m<60)){
		ans_m=(ans_m+1);
		ans_h=ans_h+ans_m/60;ans_h%=24;
		ans_m%=60;
		h1=ans_h/10;h2=ans_h%10;
		m1=ans_m/10;m2=ans_m%10;
		h_new=h1*10+m1;
		m_new=h2*10+m2;
		ans_h=h1*10+h2;ans_m=m1*10+m2;
	}
	cout<<ans_h<<' '<<ans_m;
	return 0;
}
/*
*/
