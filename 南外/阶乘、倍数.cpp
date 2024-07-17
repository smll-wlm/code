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
int q;
int f[N], cnt, ans;
void qui() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void fj(int x) {
	cnt = 1;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i != 0)
			continue;
		while (x % i == 0) {
			f[cnt] = i;
			x /= i;
		}
		cnt++;
	}
	cnt--;
}
signed main() {
	qui();
	cin >> n;
	fj(n);
	for (int i = 1; i <= cnt; i++) {
		int n1 = 0, tot = 0;
		while (n % f[i] == 0) {
			tot++;
			n /= f[i];
		}
		while (tot > 0) {
			n1 = n1 + f[i];
			int nn1 = n1;
			while (nn1 % f[i] == 0) {
				tot -= 1;
				nn1 /= f[i];
			}
		}
		ans = max(ans, n1);
	}
	if (n)
		ans = max(ans, n);
	cout << ans;
	return 0;
}
/*
*/
