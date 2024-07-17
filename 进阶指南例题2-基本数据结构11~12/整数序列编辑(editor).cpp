#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<stack>
#include<cstring>
#define int long long
using namespace std;
int i,j,n,m;
int T,sum[1000010],f[1000010];
stack<int> s1,s2;
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void solve_I(int x){
	s1.push(x);
	int it=s1.size()-1;
	sum[it+1]=sum[it]+s1.top();
	f[it+1]=max(f[it],sum[it+1]);
}
void solve_Q(int x){
	cout<<f[x]<<endl;
}
void solve_D(){
	if(!s1.empty())s1.pop();
}
void solve_L(){
	if(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}
}
void solve_R(){
	if(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
		int it=s1.size()-1;
		sum[it+1]=sum[it]+s1.top();
		f[it+1]=max(f[it],sum[it+1]);
	}
}
signed main()
{
	quickcin();
	cin>>T;
	memset(f,-0x3f3f3f,sizeof(f));
	while(T--){
		char c;
		cin>>c;
		int x;
		if(c=='I'||c=='Q'){
			cin>>x;
			if(c=='I')
				solve_I(x);
			else
				solve_Q(x);
		}
		else{
			if(c=='D'){
				solve_D();
			}
			if(c=='L'){
				solve_L();
			}
			if(c=='R'){
				solve_R();
			}
		}
	}
	return 0;
}
