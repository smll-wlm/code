#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define fir first
#define sec second
#define int long long
#define in_vo inline void
#define in_ll inline long long
using namespace std;
const int N=30;
int n,m;
int a[N][N],f[N][N];
int edx,edy,mx,my;
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void init(){
	f[0][0]=1;
	a[mx][my]=1;f[mx][my]=0;
	if(mx-1>=0&&my-2>=0&&mx-1<N&&my-2<N)a[mx-1][my-2]=1;
	if(mx+1>=0&&my-2>=0&&mx+1<N&&my-2<N)a[mx+1][my-2]=1;
	if(mx-1>=0&&my+2>=0&&mx-1<N&&my+2<N)a[mx-1][my+2]=1;
	if(mx+1>=0&&my+2>=0&&mx+1<N&&my+2<N)a[mx+1][my+2]=1;
	if(mx-2>=0&&my-1>=0&&mx-2<N&&my-1<N)a[mx-2][my-1]=1;
	if(mx+2>=0&&my-1>=0&&mx+2<N&&my-1<N)a[mx+2][my-1]=1;
	if(mx-2>=0&&my+1>=0&&mx-2<N&&my+1<N)a[mx-2][my+1]=1;
	if(mx+2>=0&&my+1>=0&&mx+2<N&&my+1<N)a[mx+2][my+1]=1;
}
signed main()
{
	cin>>edx>>edy>>mx>>my;
	init();
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!a[i][j])
				f[i][j]=(f[i][j-1]+f[i-1][j]);
		}
	}
	cout<<f[edx][edy];
	return 0;
}
