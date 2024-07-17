#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector>
#define int long long
using namespace std;
int n,m,t;
vector<int> s;
int cnt,a[110];
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void dfs(int step){
	if(cnt<20&&step>n){
		for(auto it:s){
			cout<<it;
		}
		for(int i=t-1;i>=0;i--){
			cout<<a[i];
		}
		cout<<endl;
		cnt++;
		return;
	}
	if(cnt>=20)return;
	if(t){
		s.push_back(a[--t]);
		dfs(step);
		a[t++]=s.back();
		s.pop_back();
	}
	a[t++]=step;
	dfs(step+1);
	t--;
	return;
}
signed main()
{
	quickcin();
	cin>>n;
	dfs(1);
	return 0;
}
