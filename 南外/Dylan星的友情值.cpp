#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector>
#define int long long
using namespace std;
int n,m;
int ans;
int cnt;
struct node{
	int num1,num0;
}a[50];
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
signed main()
{
	quickcin();
	cin>>n;int len=0;
	while(n--){
		int x,len1=0;
		int j=0;
		cin>>x;
		while(x!=0&&j<25){
			if(x&1){
				a[++j].num1++;
			}
			else a[++j].num0++;
			x>>=1;
		}
		len=max(len,j);
		while(j<25){
			a[++j].num0++;
		}
//		cout<<111<<endl;
	}
	cnt=1;
	for(int i=1;i<=20;i++){
		ans=ans+(a[i].num1*a[i].num0)*cnt;
		cnt<<=1;
//		cout<<ans<<' ';
	}
	cout<<ans;
	return 0;
}
