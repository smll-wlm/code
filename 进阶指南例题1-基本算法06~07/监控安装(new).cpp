#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<cmath>
#define int long long
using namespace std;
const int N=1e3+10;
int i,j,n,m;
struct node{
	double x,y;
	int vis;
}a[N];
int ans;
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
bool cmp(node a1,node b1){
	return a1.y<b1.y;
}
signed main()
{
	quickcin();
	cin>>n>>m;
	int flag=0;
	for(i=1;i<=n;i++){
		double p,q,w;
		cin>>p>>q;
//		q=abs(q);
		if(q>m){
			flag=1;
		}
		w=sqrt(m*m-q*q);
		a[i].x=p-w;
		a[i].y=p+w;
	}
	if(flag==1){
		cout<<-1;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	double it=a[1].y;
	ans++;
	for(i=2;i<=n;i++){
		if(it>a[i].x)continue;
		if(it<=a[i].x){
			ans++;
			it=a[i].y;
		}
	}
	cout<<ans;
	return 0;
}
