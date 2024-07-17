#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define int long long
#define debug cout<<"debug";
using namespace std;
int n,m;
int t,te;
int a[1000010];
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
signed main(){
	quickcin();
	
	int k=0;
	while(1){
		cin>>t;
		k++;
		memset(a,0,sizeof(a));
		if(t==0){
			return 0;
		}
		for(int i=1;i<=t;i++){
			cin>>n;
			for(int j=1;j<=n;j++){
				int x1;
				cin>>x1;
				a[x1]=i;
			}
		}
//		debug
		queue<int> team,peo[1010];
		cout<<"Scenario #"<<k<<"\n";
		string s;
		while(1){
			cin>>s;
			if(s[0]=='S')break;
			if(s=="ENQUEUE"){
				int x1;
				cin>>x1;
				te=a[x1];
				if(peo[te].empty())team.push(te);
				peo[te].push(x1);
			}
			else{
				te=team.front();
				cout<<peo[te].front()<<"\n";
				peo[te].pop();
				if(peo[te].empty())team.pop();
			}
		}
		cout<<"\n";
	}
	return 0;
}
