#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define int long long
using namespace std;
const int N=3e6+10;
int n,m,a,b;
int n1,n2;
int ans=0,d[N],v[N],f[N];
queue<int> q;
int ver[N],ne[N],tot,he[N];
void quickcin(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
}
void add(int x,int y){
	ver[++tot]=y;
	ne[tot]=he[x];
	he[x]=tot;
}
void bfs(){
	q.push(1);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=he[t];i;i=ne[i]){
			int y=ver[i];
			if(v[y]==0){
				d[y]=d[t]+1;
				v[y]=1;
				q.push(y);
			}
		}
	}
	q.push(n1+n2);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=he[t];i;i=ne[i]){
			int y=ver[i];
			if(v[y]==0){
				d[y]=d[t]+1;
				v[y]=1;
				q.push(y);
			}
		}
	}
}
signed main(){
	quickcin();
	cin>>n1>>n2>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	memset(d,0x3f,sizeof(d));
	d[1]=d[n1+n2]=0;
	v[1]=v[n1+n2]=1;
	bfs();
	int ans1=0,ans2=0;
	for(int i=1;i<=n1;i++){
		ans1=max(ans1,d[i]);
	}
	for(int i=n1+1;i<=n1+n2;i++){
		ans2=max(ans2,d[i]);
	}
	cout<<ans1+ans2+1;
	return 0;
}
