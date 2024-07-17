#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,m;
int a[N];
signed main(){
	cin>>n;
	int x=n;
	m=1;
	while(a[x]==0){
		a[x]=1;
		m++;
		if(x%2==0){
			x/=2;
		}
		else{
			x=x*3+1;
		}
	}
	cout<<m;
	return 0;
} 
