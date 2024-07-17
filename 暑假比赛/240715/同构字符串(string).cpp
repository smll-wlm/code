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
const int N=1e7+10;
int st[N],a[N];
int b[N];
int n,m;
int flag;
string s;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_ll chk(int x1,int y1,int s1,int x2,int y2,int s2,int len){
	for(int i=0;i<len;i++){
		int x,y;
		if(st[x1]+i>y1){
			x=a[st[x1]+i-len];
		}
		else{
			x=a[st[x1]+i];
		}
		if(st[x2]+i>y2){
			y=a[st[x2]+i-len];
		}
		else{
			y=a[st[x2]+i];
		}
		if(x!=y)return 0;
	}
	return 1;
}
in_vo ff(int l,int r,int len){
	for(int i=1;i<=len;i++){
		b[i]=a[l+i-1];
	}
	for(int i=1;i<=len;i++){
		b[i+len]=b[i];
	}
	int i=1,j=2,k;
	while(i<=len&&j<=len){
		for(k=0;k<len&&b[i+k]==b[j+k];k++);
		if(k==len)break;
		if(b[i+k]>b[j+k]){
			i=i+k+1;
			if(i==j)i++;
		}
		else{
			j=j+k+1;
			if(j==i)j++;
		}
	}
	st[l]=min(l+i-1,l+j-1);
}
in_ll chk1(int x){
	ff(1,x,x);
	for(int i=x+1;i<=n;i+=x){
		ff(i,i+x-1,x);
		if(!chk(1,x,st[1],i,i+x-1,st[i],x))return 0;
	}
	return 1;
}
in_vo init(){
	flag=0;
	for(int i=0;i<=n;i++){
		st[i]=a[i]=b[i]=0;
	}
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
		if(n==1){
			cout<<"No\n";
			continue;
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
		if(flag==1){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
	return 0;
}
