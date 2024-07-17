#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
int a[100010];
long long ans;
int main() {
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (i = 1; i <= n; i++) {
		ans += m * a[i];
		if (m != 1)
			m--;
	}
	printf("%lld", ans);
	return 0;
}

