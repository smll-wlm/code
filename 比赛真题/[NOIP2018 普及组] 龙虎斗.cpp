#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define fir first
#define sec second
#define int long long
#define in_vo inline void
#define in_ll inline long long
using namespace std;
const int N=1e5+10;
int n,m;
int c[N],p1,s1,s2;
int q1,q2,ans,cnt=1e9;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cin>>m>>p1>>s1>>s2;
	c[p1]+=s1;
	for(int i=1;i<m;i++){
		q1=q1+c[i]*(m-i);
	}
	for(int i=m+1;i<=n;i++){
		q2+=c[i]*(i-m);
	}
	cnt=abs(q1-q2);
	ans=m;
	for(int i=1;i<=n;i++){
		if(i<m){
			q1=q1+s2*(m-i);
			if(abs(q1-q2)<cnt){
				cnt=abs(q1-q2);
				ans=i;
			}
			q1=q1-s2*(m-i);
		}
		if(i>m){
			q2=q2+s2*(i-m);
			if(abs(q1-q2)<cnt){
				cnt=abs(q1-q2);
				ans=i;
			}
			q2=q2-s2*(i-m);
		}
	}
	cout<<ans;
	return 0;
}
