#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
int a[1010][1010], f[1010];
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	f[2] = (a[1][2] - a[1][3] + a[2][3]) / 2;
	for (i = 1; i <= n; i++) {
		if (i == 2)
			continue;
		f[i] = a[i][2] - f[2];
	}
	for (i = 1; i <= n; i++) {
		printf("%d ", f[i]);
	}
	return 0;
}
