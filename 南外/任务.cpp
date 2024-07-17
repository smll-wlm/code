#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans, sum;
int i, j, n, m, len;
struct node {
	int t, end;
} a[200010];
bool cmp(node x, node y) { return x.end < y.end; }
priority_queue<int> q;
signed main() {
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld %lld", &a[i].t, &a[i].end);
	}
	sort(a + 1, a + 1 + n, cmp);
	for (i = 1; i <= n; i++) {
		if (sum + a[i].t > a[i].end) {
			if (q.size() > 0) {
				int x = q.top();
				if (x > a[i].t) {
					if (sum - x + a[i].t <= a[i].end) {
						q.pop();
						q.push(a[i].t);
						sum = sum - x + a[i].t;
					}
				}
			}
		} else {
			sum += a[i].t;
			q.push(a[i].t);
			ans++;
		}
	}
	printf("%lld", ans);
	return 0;
}
