#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<unordered_map>
#define pii pair<int,int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
const int N=1e6+10;
using namespace std;
int n,m;
int a[N];
struct node{
	int lmax,rmax,sum,dat,l,r;
};
node tr[N];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo build(int id,int l,int r){
	tr[id].l=l;tr[id].r=r;
	if(l==r){
		tr[id].dat=tr[id].sum=tr[id].lmax=tr[id].rmax=a[l];
		return;
	}
	int mid=l+r>>1;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	tr[id].sum=tr[id*2].sum+tr[id*2+1].sum;
	tr[id].lmax=max(tr[id*2].lmax,tr[id*2].sum+tr[id*2+1].lmax);
	tr[id].rmax=max(tr[id*2+1].rmax,tr[id*2+1].sum+tr[id*2].rmax);
	tr[id].dat=max(max(tr[id*2].dat,tr[id*2+1].dat),tr[id*2].rmax+tr[id*2+1].lmax);
}
in_vo change(int id,int x,int d){
	if(tr[id].l==tr[id].r){
		tr[id].dat=d;
		tr[id].sum=d;
		tr[id].lmax=d;
		tr[id].rmax=d;
		return;
	}
	int mid=tr[id].l+tr[id].r>>1;
	if(x<=mid)change(id<<1,x,d);
	else change(id*2+1,x,d);
	tr[id].sum=tr[id*2].sum+tr[id*2+1].sum;
	tr[id].lmax=max(tr[id*2].lmax,tr[id*2].sum+tr[id*2+1].lmax);
	tr[id].rmax=max(tr[id*2+1].rmax,tr[id*2+1].sum+tr[id*2].rmax);
	tr[id].dat=max(max(tr[id*2].dat,tr[id*2+1].dat),tr[id*2].rmax+tr[id*2+1].lmax);
}
node ask(int id,int l,int r){
	if(l<=tr[id].l&&r>=tr[id].r){
		return tr[id];
	}
	int mid=(tr[id].l+tr[id].r)>>1,res=-(1<<30);
	node a1,b1,c1;
	a1.dat=a1.sum=a1.lmax=a1.rmax=res;
	b1.dat=b1.sum=b1.lmax=b1.rmax=res;
	c1.sum=0;
	if(l<=mid){
		a1=ask(id<<1,l,r);
		c1.sum+=a1.sum;
	}
	if(r>mid){
		b1=ask(id*2+1,l,r);
		c1.sum+=b1.sum;
	}
	c1.dat=max(max(a1.dat,b1.dat),a1.rmax+b1.lmax);
	c1.lmax=max(a1.lmax,b1.lmax+a1.sum);
	if (l>mid) c1.lmax=max(c1.lmax,b1.lmax);
	c1.rmax=max(b1.rmax,b1.sum+a1.rmax);
	if (r<=mid) c1.rmax=max(c1.rmax,a1.rmax);
	return c1;
}
signed main(){
	qui();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	while(m--){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1){
			if(x>y)swap(x,y);
			cout<<ask(1,x,y).dat<<"\n";
		}
		else{
			change(1,x,y);
		}
	}
	return 0;
}
/*
*/
