#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<bitset>
#include <iomanip>
#define pii pair<int,int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x,y) memset(x,y,sizeof(x))
const int N=1e2+10;
using namespace std;
int n,m;
int ans;
int hp_c;
struct node{
	int at,hp,def,ex;
	string s;
}a[N];
int ad_at,ad_def,ad_hp,at1,hp1,def1;
int e[1<<20];
int f[1<<20];
void qui(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
in_vo init(){
	mem(f,0x3f);mem(e,0);
	hp_c=0;
}
in_ll pd(int x,int y){
	node ds;
	int lev=e[y]/100;
	int at2=at1+lev*ad_at,def2=def1+lev*ad_def,hp2=hp1+lev*ad_hp-f[y];
	ds=a[x];
	// cout<<' '<<at2<<' '<<def2<<' '<<hp2<<endl;
	int cs1=ceil((double)ds.hp/max(1ll,at2-ds.def));
	int cs2=ceil(hp2/max(1ll,ds.at-def2));
	if(cs1<=cs2){
		hp_c=(cs1-1)*max(1ll,ds.at-def2);
		// cout<<cs1<<' '<<cs2<<' '<<hp_c<<endl;
		return 1;
	}
	return 0;
}
signed main(){
	qui();
	while(cin>>at1>>def1>>hp1>>ad_at>>ad_def>>ad_hp){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].s>>a[i].at>>a[i].def>>a[i].hp>>a[i].ex;
		}
		f[0]=0;
		m=1<<n;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(((i>>j)&1)==0){
					if(pd(j+1,i)){
						e[i+(1<<j)]=e[i]+a[j+1].ex;
						f[i+(1<<j)]=min(f[i+(1<<j)],f[i]+hp_c);
					}
				}
			}
		}
		if(f[m-1]>e[m-1]/100*ad_hp+hp1){
			cout<<"Poor LvBu,his period was gone."<<'\n';
		}
		else{
			cout<< e[m-1]/100*ad_hp+hp1-f[m-1]<<'\n';
		}
	}
	return 0;
}
/*
*/
