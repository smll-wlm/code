#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include<string>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
#include<unordered_map>
#include <set>
#define pii pair<int, int>
#define y1 y114514
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=2e7+10;
int st[N],a[N];
int n,m;
int flag;
string s;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll chk(int x1,int y1,int s1,int x2,int y2,int s2,int len){
	for(int i=0;i<len;i++){
		if(st[x1]+i>y1){
			if(a[st[x1]+i-len]!=a[st[x2]+i>y2]){
				if(st[x2]+i-len)return 0;
			}
		}
	}
	return 1;
}
in_vo ff(int l,int r,int len){
	for(int i=1;i<=len;i++){
		b[i]=a[x+i-1];
	}
	for(int i=1;i<=len;i++){
		
	}
}
in_vo chk1(int x){
	ff(1,x,x);
	for(int i=x+1;i<=n;i+=x){
		ff(i,i+x-1,x);
		if(!chk(1,x,st[1],i,i+x-1,st[i],x))return 0;
	}
	return 1;
}
in_vo init(){
	flag=0;
}
signed main()
{
	qui();
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		init();
		cin>>s;
		for(int i=1;i<=n;i++){
			a[i]=s[i-1]-'a'+1;
		}
		for(int i=1;i<=n/i;i++){
			if(n%i==0){
				if(chk1(i)){
					flag=1;
					break;
				}
				if(i>1&&i*i!=n){
					if(chk1(n/i)){
						flag=1;
						break;
					}
				}
			}
		}
		cout<<flag==1?"Yes\n":"No\n";
	}
	return 0;
}
