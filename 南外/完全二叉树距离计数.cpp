#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
const int mod = 998244353;
const int N = 2e6 + 10;
int p[N];
int ans;
int n, m;
void qui() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
signed main() {
	cin >> n >> m;
	p[0] = 1;
	for (int i = 1; i <= 2 * n; i++) {
		p[i] = p[i - 1] * 2 % mod;
	}
	for (int i = 1; i <= n; i++) {
		int hi = n - i;
		if (m <= hi) {
			ans = (ans + p[m] % mod * p[i - 1] % mod) % mod;
		}
		int r = min(m - 1, hi);
		int l = m - r;
		if (l > r)
			continue;
		ans = (ans + (r - l + 1) % mod * p[m - 2] % mod * p[i - 1] % mod) % mod;
	}
	ans = ans * 2 % mod;
	cout << ans;
	return 0;
}
