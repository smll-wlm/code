#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k, m, f, t, tn;
int pos[N], l[N], r[N], ans[N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		pos[x] = i;
		l[i] = i - 1;
		r[i] = i + 1;
	}
	t = 2;
	tn = n;
	while (n) {
		t = 3 - t;
		while (ans[pos[n]]) n--;
		if (!n)
			break;
		ans[pos[n]] = t;
		int j = l[pos[n]], k = r[pos[n]];
		for (int i = 1; j && i <= m; i++) ans[j] = t, j = l[j];
		for (int i = 1; k && i <= m; i++) ans[k] = t, k = r[k];
		l[k] = j;
		r[j] = k;
	}
	for (int i = 1; i <= tn; i++) printf("%d", ans[i]);
	return 0;
}
