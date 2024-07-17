#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
//#define int long long
using namespace std;
const int N=5e3+10;
int n,m;
long long k,ans,ans1=1e18;
int w[N],fa[N],s[N];
struct node{
	int ff_x,ff_y;
	long long ff_z;
}a[N];
void quickcin(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
}
int find_fa(int x){
	if(x==fa[x])return x;
	return fa[x]=find_fa(fa[x]);
}
void fk_add(int x,int y){
	fa[y]=x;
	ans-=w[s[x]]+w[s[y]];
	ans+=w[s[x]+=s[y]];
}
bool cmp(node a1,node b1){return a1.ff_z<b1.ff_z;}
signed main(){
	quickcin();
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].ff_x>>a[i].ff_y>>a[i].ff_z;
	}
	sort(a+1,a+1+m,cmp);
	a[m+1].ff_z=-1;
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			s[j]=1;
			fa[j]=j;
		}
		ans=n*w[1];
		for(int j=i;j<=m;j++){
			int x=find_fa(a[j].ff_x),y=find_fa(a[j].ff_y);
			if(x!=y)fk_add(x,y);
			if(a[j+1].ff_z!=a[j].ff_z&&ans>=k){
				ans1=min(ans1,a[j].ff_z-a[i].ff_z);
				break;
			}
		}
	}
	if(ans1==1e18){
		cout<<"T_T";
	}
	else{
		cout<<ans1;
	}
	return 0;
}
//递归调用
