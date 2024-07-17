#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int n,m;
int st,ed;
vector<int> v[N];
queue<int> q;
int f[N][3],vis[N];
void bfs(int st1){
	memset(f,-1,sizeof(f));
	q.push(st1);
	f[st1][0]=0;
	vis[st1]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(auto it:v[x]){
			for(int j=0;j<=2;j++){
				if(f[it][(j+1)%3]!=-1||f[x][j]==-1){
					continue;
				}
				f[it][(j+1)%3]=f[x][j]+1;
				if(!vis[it]){
					q.push(it);
					vis[it]=1;
				}
			}
		}
	}
	return;
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	cin>>st>>ed;
	bfs(st);
	if(f[ed][0]!=-1){
		cout<<f[ed][0]/3;
	}
	else cout<<-1;
	return 0;
} 
