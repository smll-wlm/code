#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<bitset>
#define pii pair<int,int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=2e6+10;
using namespace std;
int n,m;
int q,tot;
struct node{
	int v,w,num;
}a[N];
int f[N];
int vis[N],g[N],tmp1[N];
vector<int> v;
vector<pii> tmp;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int s,v,w;
		cin>>s>>w>>v;
		a[i].num=s;a[i].v=v;a[i].w=w;
	}
	cin>>q;
	memset(f,-0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v.clear();
		for(int j=1;j<=x;j++){
			int y;
			cin>>y;
			vis[y]=1;
			v.push_back(y);
		}
		for(int j=1;j<=m;j++){
			tmp1[j]=f[j];
		}
		for(auto it:v){
			for(int j=1;j<=m;j++)g[j]=tmp1[j];
			tmp.clear();
			int s=1;
			while(a[it].num){
				if(s>a[it].num)s=a[it].num;
				tmp.push_back({s*a[it].v,s*a[it].w});
				a[it].num-=s;
				s<<=1;
			}
			for(auto [tmpv,tmpw]:tmp){
				for(int j=m;j>=tmpv;j--){
					g[j]=max(g[j],g[j-tmpv]+tmpw);
				}
			}
			for(int j=1;j<=m;j++){
				f[j]=max(f[j],g[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(a[i].num==0){
				for(int j=a[i].v;j<=m;j++){
					f[j]=max(f[j],f[j-a[i].v]+a[i].w);
				}
			}
			else{
				tmp.clear();
				int s=1;
				while(a[i].num){
					if(s>a[i].num)s=a[i].num;
					tmp.push_back({s*a[i].v,s*a[i].w});
					a[i].num-=s;
					s<<=1;
				}
				for(auto [tmpv,tmpw]:tmp){
					for(int j=m;j>=tmpv;j--){
						f[j]=max(f[j],f[j-tmpv]+tmpw);
					}
				}
			}
		}
	}
	if(f[m]<0){
		cout<<"i'm sorry...";
	}
	else{
		cout<<f[m];
	}
	return 0;
}
/*
*/
