#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<cstring>
#include<string>
#define int long long
const int N=1e6+10;
const int P=131;
using namespace std;
int n,m;
int ans;
int a[N];
char s[N];
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void calc(){
	a[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j>0&&s[i]!=s[j+1]){
			j=a[j];
		}
		if(s[i]==s[j+1])j++;
		a[i]=j;
	}
}
signed main(){
	quickcin();
	int cnt=1;
	while(1){
		scanf("%lld",&n);
		if(n==0)return 0;
		scanf("%s",s+1);
		calc();
		printf("Test case #%lld\n",cnt++);
		for(int i=2;i<=n;i++){
			if(i%(i-a[i])==0&&i/(i-a[i])>1){
				printf("%lld %lld\n",i,i/(i-a[i]));
			}
		}
		printf("\n");
	}
	return 0;
}
/*
对于一个字符串的任意循环元的长度，必然是最小循环元的长度的倍数

*/
