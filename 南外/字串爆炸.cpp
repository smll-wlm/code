#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
//#define int long long
using namespace std;
int n,m;
string s1,s2;
int a[1000010],top,a1[1000010],a2[1000010];
void quickcin()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
bool pd(int it,int len){
	int j=0;
	for(int i=it-len;i<it;i++){
		if(a[i]!=a2[j])return 0;
		j++;
	}
	return 1;
}
signed main(){
	quickcin();
	cin>>s1>>s2;
	int len1=s1.size(),len2=s2.size();
	for(int i=0;i<len1;i++){
		a1[i]=int(s1[i]);
//		cout<<a1[i]<<' ';
	}
	for(int i=0;i<len2;i++){
		a2[i]=int(s2[i]);
//		cout<<a2[i]<<' ';
	}
	for(int i=0;i<len1;i++){
		a[top++]=a1[i];
		if(top>=len2){
			while(pd(top,len2)&&top>=len2){
				top-=len2;
			}
		}
//		cout<<top<<' ';
	}
	if(top==0){
		cout<<"FRULA";
	}
	else{
		for(int i=0;i<top;i++){
			cout<<char(a[i]);
		}
	}
	return 0;
}
