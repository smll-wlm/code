#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
struct node {
	int h, num;
} a[100010];
int b[100010];
int p, ans;
int main() {
	scanf("%d%d%d", &n, &m, &p);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i].h);
		a[i].num = i;
	}
	for (i = 1; i <= n; i++) {
		if (a[i].h >= p)
			b[i]++;
		b[i] += b[i - 1];
	}
	for (i = 1, j = m; j <= n; i++, j++) {
		if (b[j] - b[i - 1] == m)
			ans++;
	}
	printf("%d", ans);
	return 0;
}
