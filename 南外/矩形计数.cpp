#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=2e3+10;
int n,m;
int ans,xx,yy;
struct node{
	int x, y;
}a[N];
int ed[N][N];
int c[N*2];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
bool cmp(node a,node b){
	if(a.y==b.y){
		return a.x<b.x;
	}
	return a.y<b.y;
}
signed main(){
	int cm;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		a[i].x=x;a[i].y=y;
		c[i]=x;
		c[i+n]=y;
	}
	sort(c+1,c+1+n+n);cm=unique(c+1,c+n*2+1)-(c+1);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		a[i].x=lower_bound(c+1,c+1+cm,a[i].x)-c;
		a[i].y=lower_bound(c+1,c+1+cm,a[i].y)-c;
		ed[a[i].x][a[i].y]=1;
		xx=max(xx,a[i].x),yy=max(yy,a[i].y);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(ed[a[i].x][a[j].y]==1&&ed[a[j].x][a[i].y]==1&&a[i].x!=a[j].x&&a[i].y!=a[j].y){
				ans++;
			}
		}
	}
	cout<<ans/4;
	return 0;
} 
