#include <bits/stdc++.h>
#define int long long
using namespace std;
int i, j, n, m, len;
int a[100010];
int ans;
bool check(int midd) {
	int cnt = 0;
	for (j = 1; j <= n; j++) {
		cnt += midd / a[j];
		if (cnt >= m)
			return 0;
	}
	return 1;
}
signed main() {
	scanf("%lld%lld", &n, &m);
	
	for (i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	int l = 1, r = 1ll << 60;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
			ans = mid;
		}
	}
	printf("%lld", ans);
	return 0;
}
