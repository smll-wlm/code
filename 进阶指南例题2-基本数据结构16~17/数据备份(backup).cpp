#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define int long long
const int N=1e5+10;
using namespace std;
int n,m,k;
int ans;
int a[N],ne[N],pre[N],d[N];
struct cmp{
	bool operator()(int x,int y){
		return a[x]>a[y];
	}
};
priority_queue<int,vector<int>,cmp > q;
inline void get(int &v){ //能读入负数
	char ch,fu=0;
	for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
	if(ch=='-') fu=1, ch=getchar();
	for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
	if(fu) v=-v;
}
signed main(){
	get(n);
	get(k);
	get(a[1]);
	for(int i=2;i<=n;i++){
		get(a[i]);
		a[i-1]=a[i]-a[i-1];
	}
	n--;
	a[0]=1e9+10;
	for(int i=1;i<=n;i++){
		q.push(i),pre[i]=i-1;
		ne[i]=i+1>n?0:i+1;
	}
	while(k--){
		int x=q.top();
		q.pop();
		while(d[x]){
			x=q.top();
			q.pop();
		}
		ans+=a[x];
		d[pre[x]]=1;
		d[ne[x]]=1;
		a[x]=a[pre[x]]+a[ne[x]]-a[x];
		q.push(x);
		pre[x]=pre[pre[x]];
		ne[x]=ne[ne[x]];
		ne[pre[x]]=x;
		pre[ne[x]]=x;
	}
	printf("%lld",ans);
	return 0;
}
/*

*/
