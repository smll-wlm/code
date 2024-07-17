#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define p u/v
#define int long long
#define debug cout<<"debug";
const int INF=-1e9;
using namespace std;
int n,m,u,v,t,q;
int a[100010];
queue<int> q1,q2,q3;
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int calc(int t1){
	int X=INF,Y=INF,Z=INF;
	if(!q1.empty())X=q1.front()+t1*q;
	if(!q2.empty())Y=q2.front()+t1*q;
	if(!q3.empty())Z=q3.front()+t1*q;//
	int x=INF;
	x=max(max(X,x),max(Y,Z));
	if(x==X){
		q1.pop();
	}
	else if(x==Y){
		q2.pop();
	}
	else{
		q3.pop();
	}
	return x;
}
signed main(){
	quickcin();
	cin>>n>>m>>q>>u>>v>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		q1.push(a[i]);
	}
	for(int i=1;i<=m;i++){
		int x=calc(i-1);
		if(!(i%t)){
			cout<<x<<' ';
		}
		int n1=x*p;
		int n2=x-n1;
		q2.push(n1-i*q);
		q3.push(n2-i*q);
	}
	cout<<endl;
	for(int i=1;i<=n+m;i++){
		int x=calc(m);
		if(i%t==0)cout<<x<<' ';
	}
	return 0;
}
