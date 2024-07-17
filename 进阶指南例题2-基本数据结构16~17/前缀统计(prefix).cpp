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
int a[N];
int tr[N][30],tot=1;
int End[N];
char s[N];
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void insert(char* str){
	int len=strlen(str),p=1;
	for(int k=0;k<len;k++){
		int ch=str[k]-'a';
		if(tr[p][ch]==0)tr[p][ch]=++tot;
		p=tr[p][ch];
	}
	End[p]++;
}
int search(char* str){
	int len=strlen(str);
	int p=1;
	int ans=0;
	for(int k=0;k<len;k++){
		p=tr[p][str[k]-'a'];
		if(p==0)return ans;
		ans+=End[p];
	}
	return ans;
}
signed main(){
	quickcin();
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		insert(s);
	}
	while(m--){
		scanf("%s",s);
		printf("%lld\n",search(s));
	}
	return 0;
}
/*

*/
