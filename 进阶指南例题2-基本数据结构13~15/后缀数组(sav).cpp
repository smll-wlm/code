#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<cstring>
#include<string>
#define int long long
const int N=3e5+10;
const int P=131;
using namespace std;
int n,m;
int sa[N],h[N],x[N],y[N],c[N],rk[N],wei[30];
char s[N];
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

signed main(){
	quickcin();
	scanf("%s",s+1);
	int len=strlen(s+1);
	n=len;
	m=122;//ascll of 'z'
	for(int i=1;i<=n;i++){
		++c[x[i]=s[i]];
	}
	for(int i=2;i<=m;i++){
		c[i]+=c[i-1];
	}
	for(int i=n;i>=1;i--){
		sa[c[x[i]]--]=i;
	}
	for(int k=1;k<=n;k<<=1){
		int num=0;
		for(int i=n-k+1;i<=n;i++){
			y[++num]=i;
		}
		for(int i=1;i<=n;i++){
			if(sa[i]>k)y[++num]=sa[i]-k;
		}
		for(int i=1;i<=m;i++){
			c[i]=0;
		}
		for(int i=1;i<=n;i++){
			++c[x[i]];
		}
		for(int i=2;i<=m;i++){
			c[i]+=c[i-1];
		}
		for(int i=n;i>=1;i--){
			sa[c[x[y[i]]]--]=y[i];
			y[i]=0;
		}
		swap(x,y);
		x[sa[1]]=1;num=1;
		for(int i=2;i<=n;i++){
			x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?num:++num;
		}
		if(num==n)break;
		m=num;
	}
	for(int i=1;i<=n;i++){
		printf("%lld ",sa[i]-1);
	}
	//
	int k=0;
	for(int i=1;i<=n;i++){
		rk[sa[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(rk[i]==1){
			continue;
		}
		if(k)--k;
		int j=sa[rk[i]-1];
		while(j+k<=n&&i+k<=n&&s[i+k]==s[j+k]){
			k++;
		}
		h[rk[i]]=k;
	}
	printf("\n");
	for(int i=1;i<=n;i++){
		printf("%lld ",h[i]);
	}
	return 0;
}
//https://blog.csdn.net/tanjunming2020/article/details/126274419
/*
sa[i]代表排名为i的后缀的第一个字母出现位置
rk[i]代表从第i位开始的后缀的排名
x[] is the first key word,y[] is the second one,with sort of x[]
c[] 为基数排序用的桶
*/
