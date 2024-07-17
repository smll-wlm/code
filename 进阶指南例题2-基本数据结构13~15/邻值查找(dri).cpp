#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#define p u/v
#define int long long
#define debug cout<<"debug";
const int N=1e5+10;
using namespace std;
int n,m,u,v,t,q;
int a[N];
set<pair<int ,int> > s;
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

signed main(){
	quickcin();
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(i==1)
		{
			s.insert({1e17,1e17});
			s.insert({-1e17,-1e17});
			s.insert(make_pair(x,i));
			continue;
		}
		auto x1=*--s.lower_bound({x,0});
		auto x2=*s.upper_bound({x,0});
//		cout<<endl<<x1.first<<' '<<x1.second<<' '<<x2.first<<' '<<x2.second<<endl;
		if(abs(x1.first-x)<abs(x2.first-x)){
			cout<<abs(x1.first-x)<<' '<<x1.second;
		}
		else if(abs(x1.first-x)>abs(x2.first-x)){
			cout<<abs(x2.first-x)<<' '<<x2.second;
		}
		else{
			auto y=min(x1,x2);
			cout<<abs(x1.first-x)<<' '<<y.second;
		}
		cout<<endl;
		s.insert({x,i});
	}
	return 0;
}
