#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector>
#define int long long
using namespace std;
const int N=5e5+10;
int w[N],t[N],c[N];
int ans,T;
int i,j,n,m;
int sq(int x){
	return x*x;
}
void merge(int l,int mid,int r){
	int i1=l,j1=mid+1,k=l;
	while(i1<=mid&&j1<=r){
		if(w[i1]<=t[j1]){
			c[k++]=w[i1++];
		}
		else{
			c[k++]=t[j1++];
		}
	}
	while(i1<=mid){
		c[k++]=w[i1++];
	}
	while(j1<=r){
		c[k++]=t[j1++];
	}
}
int get(int l,int mid,int r){
	if(r>n)return 0;
	int k=0;
	for(int i1=mid+1;i1<=r;i1++){
		t[i1]=w[i1];
	}
	sort(t+mid+1,t+r+1);
	merge(l,mid,r);
	int sum=0;
	for(int i1=l,j1=r,cnt=1;i1<j1&&cnt<=m;i1++,j1--,cnt++){
		sum+=sq(c[j1]-c[i1]);
		if(sum>T)return 0;
	}
	for(int i1=l;i1<=r;i1++)w[i1]=c[i1];
	return 1;
}
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
signed main()
{
	quickcin();
	int K;
	cin>>K;
	while(K--){
		cin>>n>>m>>T;
		for(i=1;i<=n;i++){
			cin>>w[i];
		}
		ans=0;
		int st=1,en=1;
		while(st<=n){
			int len=1;
			while(get(st,en,en+len)){
				en+=len;
				len<<=1;
			}
			while(len){
				if(get(st,en,en+len)){
					en+=len;
				}len>>=1;
			}
			st=en+1;
			en=st;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
本题中，通过倍增+归并优化
倍增：
通过长度倍增使得确定覆盖，类似十进制转二进制过程：1-2-4-8-16-...
若到达，如16，则退回8，转8+（16-8）/2=12...以此类推
归并：
对于每一个选出来长度的区间，进行进一步优化。由于时间复杂度的稳定以及良好【O（logn）】
因此选择使其确定有序。（自然可以使用sort()，但是容易超时

对于二分答案进行二分长度len，容易因数据卡常导致超时。对于一般数据，倍增与二分时不相上下的。
*/
