#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int ans = 2e9 + 10, cnt;
int i, j, n, m;
int f[2010][2010];
int a[20010];
multiset<int> s;
signed main() {
//	freopen("paint.in", "r", stdin);
//	freopen("paint.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	f[1][0] = a[1];
	for (i = 1; i <= m; i++) {
		for (j = 1; j < i; j++) {
			f[i][j] = a[i] + a[j];
		}
	}
	for (i = 2; i <= n; i++) {
		int t = 2e9;
		for (j = i + m - 1; j > i; j--) {
			if (j <= m) {
				break;
			}
			t = min(t, f[i % N][(j - m) % N]);
			f[j % N][i % N] = t + a[j];
		}
	}
	for (i = n - m + 1; i <= n; i++) {
		for (j = i - 1; i - j < m && n - j < m; j--) {
			ans = min(ans, f[i % N][j % N]);
		}
	}
	printf("%lld", ans);
	return 0;
}
