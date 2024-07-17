#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
const int N=1e6+10;
const int P=131;
using namespace std;
int n,m;
int cnt;
string s;
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
signed main(){
	quickcin();
	cin>>n>>m;
	for(int i=1;i<m;i++)
	{
		cout<<i<<' ';
		cnt+=i;
	}
	cout<<n-cnt;
	return 0;
}
