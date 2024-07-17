#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#define int long long
const int N = 1e6 + 10;
const int INF = 45000;
using namespace std;
int n, q, k, ans;
int t, a, b, c, d;
int pri[INF], cnt;
void qui() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
bool chk(int x) {
	if (x == 2 || x == 3)return 1;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)return 0;
	}
	return 1;
}
void init() {
	for (int i = 2; i <= 2e9/i; i++) {
		if (chk(i)) {
			pri[++cnt] = i;
		}
	}
	return;
}
int h(int x, int y) {
	int res = 0;
	while (x % y == 0) {
		x /= y;
		res++;
	}
	return res;
}
void calc(int p) {
	int ma = h(a, p), mb = h(b, p), mc = h(c, p), md = h(d, p);
//	printf("%lld %lld %lld %lld\n", ma, mb, mc, md);
	if (ma > mc && mb < md && mc == md) {
		return;
	}
	if (ma > mc && mb == md && mc <= md) {
		return;
	}
	if (ma == mc && mb < md && mc <= md) {
		return;
	}
	if (ma == mc && mb == md && mc <= md) {
		ans *= md - mc + 1;
		return;
	}
	ans = 0;
	return;
}
signed main() {
	qui();
	init();
	cin >> t;
	while (t--) {
		cin >> a >> c >> b >> d;
		ans = !(d % c);
		for (int i = 1; i <= cnt; i++) {
			if (d % pri[i] == 0) {
				calc(pri[i]);
				while (d % pri[i] == 0) {
					d /= pri[i];
				}
//				cout << ans << endl;
			}
		}
		if (d > 1) {
			calc(d);
		}
		cout << ans << endl;
	}
	return 0;
}
/*

*/
