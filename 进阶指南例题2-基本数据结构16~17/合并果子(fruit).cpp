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
int a[N];
priority_queue<int,vector<int>,greater<int> > q;
inline void get(int &v){ //能读入负数
	char ch,fu=0;
	for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
	if(ch=='-') fu=1, ch=getchar();
	for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
	if(fu) v=-v;
}
signed main(){
	get(n);
	for(int i=1;i<=n;i++){
		get(a[i]);
		q.push(a[i]);
	}
	while(q.size()>1){
		int x=q.top();
		q.pop();
		int y=q.top();
		q.pop();
		ans+=x+y;
		q.push(x+y);
	}
	printf("%lld",ans);
	return 0;
}
/*

*/
