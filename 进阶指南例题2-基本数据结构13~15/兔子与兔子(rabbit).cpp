#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#define int long long
const int N=1e5+10;
const int P=99991;
using namespace std;
int n,m;
unsigned int f[1000010],p[1000010];
char c[1000010];
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

signed main(){
	quickcin();
	scanf("%s",c+1);
	int len=strlen(c+1);
	scanf("%lld",&m);
	p[0]=1;
	for(int i=1;i<=len;i++){
		f[i]=f[i-1]*131+(c[i]-'a'+1);
		p[i]=p[i-1]*131;
	}
	for(int i=1;i<=m;i++){
		int l1,l2,r1,r2;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		if(f[r1]-f[l1-1]*p[r1-l1+1]==f[r2]-f[l2-1]*p[r2-l2+1]){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}
