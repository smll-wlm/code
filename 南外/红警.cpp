#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, ans = 1e9;
int t[40], v[40], f[2000];
bool pd(int x) {
	int cnt = 0;
	memset(f, 0, sizeof(f));
	for (i = 1; i <= n; i++) {
		for (j = t[i]; j <= x; j++) {
			f[j] = max(f[j], f[j - t[i]] + v[i] * (x - j));
		}
	}
	for (j = 1; j <= x; j++) {
		cnt = max(cnt, f[j]);
	}
	return cnt >= m;
}
int main() {
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &t[i], &v[i]);
	}
	int l = 1, r = 2000;
	while (l <= r) {
		int mid = l + r >> 1;
		if (pd(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	printf("%d", ans);
	return 0;
}
