#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<cstring>
#include<string>
#define int long long
const int N=1e5+10;
using namespace std;
int n,m;
int f[N],v[N],val[N*32],ver[2*N],ed[2*N],ne[N*2],he[N];
int tr[N*2][50],a[N*32][2],tot;
int ans;
inline void get(int &v){ //能读入负数
	char ch,fu=0;
	for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
	if(ch=='-') fu=1, ch=getchar();
	for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
	if(fu) v=-v;
}
inline void add(int x,int y,int z){
	ver[++tot]=y;
	ed[tot]=z;
	ne[tot]=he[x];
	he[x]=tot;
}
inline void dfs(int x){
	v[x]=1;
	for(int i=he[x];i;i=ne[i]){
		if(!v[ver[i]]){
			f[ver[i]]=f[x]^ed[i];
			dfs(ver[i]);
		}
	}
}
void insert(int x,int y,int now){
	if(y<0){
		val[x]=now;
		return;
	}
	int z=(now>>y)&1;
	if(!a[x][z]){
		a[x][z]=++tot;
	}
	insert(a[x][z],y-1,now);
}
int sear(int x,int y,int now){
	if(y<0)return val[x];
	int z=(now>>y)&1;
	if(a[x][z^1]){
		return sear(a[x][z^1],y-1,now);
	}
	else{
		return sear(a[x][z],y-1,now);
	}
}
signed main(){
	get(n);
//	scanf("%lld",&n);
	for(int i=1;i<n;i++){
		int x,y,z;
		get(x),get(y),get(z);
//		scanf("%lld%lld%lld",&x,&y,&z);
//		x++;
//		y++;
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1);tot=1;ans=0;
	insert(1,30,0);
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]^sear(1,30,f[i]));
		insert(1,30,f[i]);
	}
	printf("%lld",ans);
	return 0;
}
/*

*/
