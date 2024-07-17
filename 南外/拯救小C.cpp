#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100010];
int i, j, n, m, len;

signed main() {
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] = a[i - 1] ^ a[i];
	}
	scanf("%lld", &m);
	while (m--) {
		int l, r;
		scanf("%lld %lld", &l, &r);
		printf("%lld\n", a[r % (n + 1)] ^ a[(l - 1) % (n + 1)]);
	}
	return 0;
}
