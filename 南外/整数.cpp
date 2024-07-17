#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
int num[1010];
long long ans;
int main() {
	scanf("%d%d", &n, &m);
	if (n >= m)
		swap(n, m);
	//	for(i=1;i<=n;i++){
	//		for(j=1;j<=m;j++){
	//			int s=sqrt(i*j);
	//			if(s*s==i*j)ans++;
	//		}
	//	}
	
	// AB=k^2 a*b^2*a*c^2=(abc)^2=k^2
	for (i = 1; i <= 1000; i++) num[i] = i * i;
	for (i = 1; i <= n; i++) {
		int i1 = i;
		for (j = sqrt(n); j >= 1; j--) {
			if (i1 % num[j] == 0)
				i1 /= num[j];
		}
		ans += sqrt(m / i1);
	}
	printf("%lld", ans);
	return 0;
}
