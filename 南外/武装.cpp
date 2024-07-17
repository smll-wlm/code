#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node {
	int l, r;
} a[100010];
bool cmp(node x, node y) {
	if (x.r != y.r)
		return x.r < y.r;
	return x.l < y.l;
}
multiset<int> s;
int i, j, n, m;
int ans;
signed main() {
	scanf("%lld%lld", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%lld %lld", &a[i].l, &a[i].r);
	}
	for (i = 1; i <= m; i++) {
		int x;
		scanf("%lld", &x);
		s.insert(x);
	}
	sort(a + 1, a + 1 + n, cmp);
	for (i = 1; i <= m; i++) {
		auto it = s.lower_bound(a[i].l);
		if (it != s.end() && *it <= a[i].r) {
			ans++;
			s.erase(it);
		}
	}
	printf("%lld", ans);
	return 0;
}
