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

signed main(){
	quickcin();
	int T;
	scanf("%lld",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		ans=0;
		for(int i=1;i<=n;i++){
			s[n+i]=s[i];
		}
		int i=1,j=2,k;
		while(i<=n&&j<=n){
			k=0;
			while(k<n&&s[i+k]==s[j+k]){
				k++;
			}
			if(k==n)break;
			if(s[i+k]>s[j+k]){
				i=i+k+1;
				if(i==j)i++;
			}
			else{
				j=j+k+1;
				if(i==j)j++;
			}
		}
		ans=min(i,j);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
由于是环形，因此初始延长一倍
每次向后扫描k长度，使用类似双指针的算法，当一个到达末端后跳出
比较较小记录值，及更小的循环元。
最小表示法：
1.初始i=1,j=2;
2.直接向后扫描，比较s[i] and s[j]两个循环同构串
	I:扫描n个字符后仍然相等，则当前循环元扫描完毕，有更小的循环元；
	II：在i+k,j+k发现不同：
		拉位较后指针至前。

*/
