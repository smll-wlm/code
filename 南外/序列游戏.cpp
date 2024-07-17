#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int i, j, n, m;
long long a[N], b[N], ans;
int main() {
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	for (i = 1; i <= min(m, n); i++) {
		if (a[i] >= b[m - i + 1])
			break;
		else {
			ans += b[m - i + 1] - a[i];
		}
	}
	printf("%lld", ans);
	return 0;
}
