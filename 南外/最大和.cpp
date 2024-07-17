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
const int N = 4e5 + 10;
using namespace std;
int n, m;
int d, maxn = -1, flag;
int a[N], b[N];
void qui() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
signed main() {
	qui();
	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	while (n > 0 && m > 0) {
		int x = a[n], y = b[m];
		
		while (b[m] - a[n] > d && n > 0 && m > 0) m--;
		if (abs(b[m] - a[n]) <= d)
			maxn = max(maxn, a[n] + b[m]);
		n--;
	}
	cout << maxn;
	return 0;
}
/*
*/
