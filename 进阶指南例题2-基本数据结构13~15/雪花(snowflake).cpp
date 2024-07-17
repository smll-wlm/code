#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#define int long long
const int N=1e5+10;
const int P=99991;
using namespace std;
int n,m,u,v,tot;
int he[N],ne[N],a[N][10];
set<pair<int,int> > s;
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int H(int *a1){
	int sum1=0,mul1=1;
	for(int i=0;i<6;i++){
		sum1=(sum1+a1[i])%P;
		mul1=(int)mul1*a1[i]%P;
	}
	return (sum1+mul1)%P;
}
bool equal(int *a1,int *b1){
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			bool eq=1;
			for(int k=0;k<6;k++){
				if(a1[(i+k)%6]!=b1[(j+k)%6])eq=0;
			}
			if(eq)return 1;
			eq=1;
			for(int k=0;k<6;k++){
				if(a1[(i+k)%6]!=b1[(j-k+6)%6])eq=0;
			}
			if(eq)return 1;
		}
	}
	return 0;
}
bool insert(int *a1){
	int val=H(a1);
	for(int i=he[val];i;i=ne[i]){
		if(equal(a[i],a1))return 1;
	}
	++tot;
	memcpy(a[tot],a1,6*sizeof(int));
	ne[tot]=he[val];
	he[val]=tot;
	return 0;
}
signed main(){
	quickcin();
	cin>>n;
	for(int i=1;i<=n;i++){
		int x[10];
		for(int j=0;j<6;j++){
			cin>>x[j];
		}
		if(insert(x)){
			cout<<"Twin snowflakes found.";
			return 0;
		}
	}
	cout<<"No two snowflakes are alike.";
	return 0;
}
