#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<cstring>
#include<string>
//#define int long long
const int N=1e5+10;
using namespace std;
int n,m;
int a[N];
int tr[N*32][10],tot=1;
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void insert(int a1){
	int p=1;
	for(int k=31;k>=0;k--){
		int ch=(a1>>k)&1;
		if(tr[p][ch]==0)tr[p][ch]=++tot;
		p=tr[p][ch];
	}
}
int search(int a1){
	int p=1;
	int ans=0;
	for(int k=31;k>=0;k--){
		int ch=(a1>>k)&1;
		if(tr[p][ch^1]){
			p=tr[p][ch^1];
			ans|=(1<<k);
		}
		else{
			p=tr[p][ch];
		}
	}
	return ans;
}
signed main(){
//	quickcin();
	scanf("%d",&n);
	int ans1=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		insert(a[i]);
		ans1=max(ans1,search(a[i]));
	}
	printf("%d\n",ans1);
	return 0;
}
/*

*/
