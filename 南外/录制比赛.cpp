#include <bits/stdc++.h>
using namespace std;
struct node {
	int l, r;
} a[1010];
bool cmp(node x, node y) { return x.l < y.l; }
multiset<int> s;
int i, j, n, m;
int ans;
int main() {
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld %lld", &a[i].l, &a[i].r);
	}
	sort(a + 1, a + 1 + n, cmp);
	for (i = 1; i <= n; i++) {
		while (!s.empty() && *s.begin() <= a[i].l) {
			s.erase(s.begin());
		}
		s.insert(a[i].r);
		ans++;
		if (s.size() > 2) {
			s.erase(prev(s.end()));
			ans--;
		}
	}
	printf("%lld", ans);
	return 0;
}
