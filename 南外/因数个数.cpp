#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <map>
#define pii pair<int, int>
#define int long long
#define fir first
#define sec second
#define in_vo inline void
#define in_ll inline long long
#define mem(x, y) memset(x, y, sizeof(x))
const int N = 1e4 + 10;
const int mod = 998244353;
using namespace std;
int n, m;
int ans;
int a[N], f[N];
map<int, int> m1, m2;
void qui() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
in_ll sqrt3(int x) {
	int l = 1, r = 2e6;
	int ans=0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (mid * mid * mid <= x) {
			l = mid + 1;
			ans=mid;
		} else {
			r = mid - 1;
		}
	}
	return ans;
}
in_ll gcd(int x, int y) { return !y ? x : gcd(y, x % y); }
signed main() {
	qui();
	ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int q2 = sqrt(a[i]);
		int q4 = sqrt(q2);
		int q3 = sqrt3(a[i]);
		if (q2 * q2 == a[i]) {
			if (q4 * q4 == q2) {
				m1[q4] += 4;
			} else {
				m1[q2] += 2;
			}
		} else if (q3 * q3 * q3 == a[i]) {
			m1[q3] += 3;
		} else {
			f[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x = __gcd(a[i], a[j]);
			if (x != 1 && a[i] != a[j] && f[i]) {
				m1[x]++;
				m1[a[i] / x]++;
				f[i] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (f[i]) {
			m2[a[i]]++;
		}
	}
	for (auto it : m1) {
		ans = ans * (it.sec + 1) % mod;
	}
	for (auto it : m2) {
		ans = ans * (it.sec + 1) % mod * (it.sec + 1) % mod;
	}
	cout << ans;
	return 0;
}
/*
http://www.nfls.com.cn:20035/submission/1142605
*/
