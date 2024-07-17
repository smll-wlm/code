#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010];
int i, j, n, m, len;
map<int, int> b;
signed main() {
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	int cnt = 0, base = 1, mx = 0, ans = 1e9 + 10;
	for (i = 2; i <= n; i++) {
		if (a[i] > a[i - 1])
			cnt++;
		if (a[i] < a[i - 1])
			cnt--;
		if (cnt == 0 && a[i] == a[1]) {
			base++;
		}
		if (cnt != 0 && (a[i] - a[1]) % cnt == 0) {
			int k = (a[i] - a[1]) / cnt;
			b[k]++;
			if (b[k] == mx)
				ans = min(ans, k);
			if (b[k] > mx) {
				ans = k;
				mx = b[k];
			}
		}
	}
	printf("%lld\n%lld", mx + base, ans);
	return 0;
}
