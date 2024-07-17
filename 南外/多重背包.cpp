#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int f[N], w[N], v[N], s[N], a, b, c, xb, i, j;
int main() {
	int n, m;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c >> a >> b;
		int t = 1;
		while (c >= t) {
			v[xb] = a * t;
			w[xb] = b * t;
			c -= t;
			t = t << 1;
			xb++;
		}
		if (c > 0) {
			v[xb] = a * c;
			w[xb] = b * c;
			xb++;
		}
	}
	for (i = 0; i < xb; i++) {
		for (j = m; j >= v[i]; j--) {
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	cout << f[m];
	return 0;
}
