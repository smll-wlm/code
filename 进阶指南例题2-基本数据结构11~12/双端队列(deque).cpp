#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
int i,j,n,m;
struct node{
	int num,bh;
}a[200010];
int ans,cnt,mx[200010],mn[200010];
bool cmp(node x,node y){
	return x.num==y.num? x.bh<y.bh:x.num>y.num;
}
signed main(){
	IOS;TIE;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].num;
		a[i].bh=i;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++){
		if(a[i].num!=a[i-1].num||i==1){
			mx[cnt]=a[i-1].bh;
			mn[++cnt]=a[i].bh;
		}
	}
	mx[cnt]=a[n].bh;
//	for(i=1;i<=n;i++){/
//		cout<<a[i].num<<' '<<a[i].bh<<" cs2 "<<endl;
//		cout<<mx[i]<<' '<<mn[i]<<" cs1 "<<endl;
//	}/
	int h=1<<30,zt=1;
	for(i=1;i<=cnt;i++){
		if(zt==0){
			if(h>mx[i]){
				h=mn[i];
			}
			else{
				zt=1;
				h=mx[i];
			}
		}
		else if(zt==1){//down
			if(h<mn[i]){
				h=mx[i];
			}
			else{
				zt=0;
				h=mn[i];
				ans++;
			}
		}
//		cout<<i<<' '<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
