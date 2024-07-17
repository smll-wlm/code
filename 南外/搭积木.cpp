#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
int b2[300010], b1[300010], a[300010];
int num, ans = 1e9 + 10, h;
int main() {
	scanf("%d%d%d", &n, &m, &h);
	for (i = 1 + m; i <= n + m; i++) {
		scanf("%d", &a[i]);
		num += a[i];
	}
	if (num < m * h) {
		printf("-1");
		return 0;
	}
	for (i = 1; i <= n + 2 * m; i++) {
		if (a[i] > h) {
			b1[i] += a[i] - h;
		}
		if (a[i] < h) {
			b2[i] -= a[i] - h;
		}
		b1[i] += b1[i - 1];
		b2[i] += b2[i - 1];
	}
	for (i = 1; i <= n + m; i++) {
		int x, y;
		x = b1[i + m] - b1[i];
		y = b2[i + m] - b2[i];
		ans = min(ans, max(x, y));
	}
	printf("%d", ans);
	return 0;
}
