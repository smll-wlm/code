#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define int long long
const int N=2e3+10;
using namespace std;
int n,m,k;

int a[N][N],now[N],ans[N];
struct node{
	int x,y;
	int ok;
};
bool operator < (node a1,node b1){
	return a[k][a1.y]+now[a1.x]>a[k][b1.y]+now[b1.x];
}
priority_queue<node > p,k1;
inline void get(int &v){ //能读入负数
	char ch,fu=0;
	for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
	if(ch=='-') fu=1, ch=getchar();
	for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
	if(fu) v=-v;
}
signed main(){
	get(n),get(m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
		sort(a[i]+1,a[i]+1+m);
		if(i==1){
			for(int j=1;j<=m;j++){
				now[j]=a[i][j];
			}
		}
	}
	int i1=1,j1=1;
	for(k=2;k<=n;k++){
		p=k1;
		p.push(node{1,1,1});
		for(int kk=1;kk<=m;kk++){
			node pd=p.top();
			p.pop();
			ans[kk]=now[pd.x]+a[k][pd.y];
			i1=pd.x;
			j1=pd.y;
			p.push(node{i1,j1+1,0});
			if(pd.ok==1){
				p.push(node{i1+1,j1,1});
			}
		}
		for(int kk=1;kk<=m;kk++){
			now[kk]=ans[kk];
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",now[i]);
	}
	return 0;
}
/*

*/
