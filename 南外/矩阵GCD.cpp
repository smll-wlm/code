#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
#define pii pair<int, int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long

#define y1 y114514
const int N = 4e5 + 10;
using namespace std;
int n, m;
int q, ans, k;
int a[N], b[N];
void qui() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
in_ll gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
signed main() {
	qui();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		k = gcd(gcd(a[i], b[i]), k);
	}
	for (int i = 1; i <= n; i++) {
		a[i] /= k;
		b[i] /= k;
	}
	while (q--) {
		ans = 0;
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				ans = gcd(a[i] + b[j], ans);
				if (ans == 1)
					break;
			}
			if (ans == 1)
				break;
		}
		cout << ans * k << "\n";
	}
	return 0;
}
/*
*/
