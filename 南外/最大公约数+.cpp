#include <bits/stdc++.h>
using namespace std;
const int P = 1e9;
int i, j, n, m;
int t;
map<int, int> mp;
long long ans = 1;
void G(int x) {
	for (int i1 = 2; i1 * i1 <= x; i1++) {
		for (; x % i1 == 0; x /= i1) {
			mp[i1]++;
		}
	}
	if (x > 1)
		mp[x]++;
}
void T(int x) {
	for (int i1 = 2; i1 * i1 <= x; i1++) {
		for (; x % i1 == 0; x /= i1) {
			if (mp[i1] > 0) {
				ans *= i1;
				mp[i1]--;
				if (ans >= P)
					ans %= P;
			}
		}
	}
	if (x > 1 && mp[x] > 0) {
		ans *= x;
		mp[x]--;
		if (ans >= P)
			t = 1, ans %= P;
	}
}
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		G(x);
	}
	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		T(x);
	}
	if (t)
		printf("%09lld", ans);
	else
		printf("%lld", ans);
	return 0;
}
