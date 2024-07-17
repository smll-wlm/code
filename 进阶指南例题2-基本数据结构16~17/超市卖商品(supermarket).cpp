#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define int long long
const int N=1e5+10;
using namespace std;
int n,m;
priority_queue<int,vector<int> ,greater<int> > p;
pair<int,int> a[N];
int ans;
inline void get(int &v){ //能读入负数
	char ch,fu=0;
	for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
	if(ch=='-') fu=1, ch=getchar();
	for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
	if(fu) v=-v;
}
signed main(){
	while(scanf("%lld",&n)!=EOF){
		if(n==0){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			get(a[i].second);
			get(a[i].first);
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(a[i].first>p.size())
				p.push(a[i].second);
			else if(a[i].first==p.size()&&a[i].second>p.top()){
				p.pop();
				p.push(a[i].second);
			}
		}
		int ans=0;
		while(!p.empty()){
			ans+=p.top();
			p.pop();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*

*/
