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
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=1e6+10;
const int mod=998244353;
const int inf=1e9;
using namespace std;
int n,m;
int cc;
double ans;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
inline double pd(char c[5]){
	switch(c[1]){
		case 'A':{
			if(c[2]=='-')return 3.7;
			return 4.0;
		}
		case 'B':{
			if(c[2]=='-')return 2.7;
			if(c[2]=='+')return 3.3;
			return 3.0;
		}
		case 'C':{
			if(c[2]=='-')return 1.7;
			if(c[2]=='+')return 2.3;
			return 2.0;
		}
		case 'D':{
			if(c[2]=='-')return 1.0;
			return 1.3;
		}
		case 'F':{
			return 0;
		}
	}
}
signed main(){
	// qui();
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		int x;
		char c[5];
		c[1]=c[2]=0;
		scanf("%lld",&x);
		scanf("%s",c+1);
		if(c[1]=='P'||c[1]=='N')continue;
		cc+=x;
		ans+=x*1.00*pd(c);
	}
	if(ans==0){
		printf("0.00");
		return 0;
	}
	printf("%.2lf",ans/cc);
	return 0;
}
/*
*/
