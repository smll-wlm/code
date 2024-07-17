#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int n,m;
vector<int> v[100010];
void quickcin(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
}
signed main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(v[i].size()==n-1){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}
