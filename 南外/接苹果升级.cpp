#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
int l, r, n1, ans;
int a[30];
int main() {
	scanf("%d %d", &n1, &m);
	scanf("%d", &n);
	l = 1, r = l + m - 1;
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] >= l && a[i] <= r)
			continue;
		if (a[i] > r) {
			ans += a[i] - r;
			l = l + a[i] - r;
			r = a[i];
			
		} else {
			ans += l - a[i];
			r = r - l + a[i];
			l = a[i];
		}
	}
	printf("%d", ans);
	return 0;
}
