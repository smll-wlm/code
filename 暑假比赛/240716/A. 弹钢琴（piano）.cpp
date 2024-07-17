#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include<string>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
#include<map>
#define pii pair<int, int>
#define y1 y114514
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=1e6+10;
int n,m;
int a[N];
int t,ans;
map<int,int> mp;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main()
{
	freopen("piano.in","r",stdin);
	freopen("piano.out","w",stdout);
//	qui();
//	cin>>n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ff=a[1],base=1,ansr=0,ansk=0,cnt=0;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			cnt++;
		}
		if(a[i]<a[i-1]){
			cnt--;
		}
		if(cnt==0&&a[i]==ff){
			base++;
		}
		else if(cnt!=0&&(a[i]-ff)%cnt==0){
			int k=(a[i]-ff)/cnt;
			mp[k]++;
			if(mp[k]==ansr){
				ansk=min(ansk,k);
			}
			if(mp[k]>ansr){
				ansr=mp[k];
				ansk=k;
			}
		}
	}
//	cout<<ansr+base<<'\n'<<ansk;
	printf("%lld\n%lld",ansr+base,ansk);
	return 0;
}


